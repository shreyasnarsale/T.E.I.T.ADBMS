> use retailDB;
switched to db retailDB
> 
> // Products Collection
> db.products.insertMany([
...   {
...     _id: "product1",
...     product_name: "Laptop",
...     category: "Electronics",
...     subcategory: "Computers",
...     brand: "TechBrand",
...     price: 1200
...   },
...   {
...     _id: "product2",
...     product_name: "Smartphone",
...     category: "Electronics",
...     subcategory: "Mobile Phones",
...     brand: "PhoneBrand",
...     price: 800
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "product1", "product2" ] }
> 
> // Time Collection
> db.time.insertMany([
...   {
...     _id: "time1",
...     date: "2025-09-18",
...     day: 18,
...     month: 9,
...     quarter: 3,
...     year: 2025
...   },
...   {
...     _id: "time2",
...     date: "2025-09-19",
...     day: 19,
...     month: 9,
...     quarter: 3,
...     year: 2025
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "time1", "time2" ] }
> 
> // Stores Collection
> db.stores.insertMany([
...   {
...     _id: "store1",
...     store_name: "Main Street Store",
...     location: {
...       city: "Mumbai",
...       state: "MH",
...       country: "INDIA"
...     }
...   },
...   {
...     _id: "store2",
...     store_name: "Downtown Store",
...     location: {
...       city: "Pune",
...       state: "MH",
...       country: "INDIA"
...     }
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "store1", "store2" ] }
> 
> // Customers Collection
> db.customers.insertMany([
...   {
...     _id: "customer1",
...     customer_name: "Amit Sharma",
...     gender: "Male",
...     age: 30,
...     income_group: "50k-70k",
...     customer_segment: "Regular"
...   },
...   {
...     _id: "customer2",
...     customer_name: "Avani Patil",
...     gender: "Female",
...     age: 25,
...     income_group: "70k-100k",
...     customer_segment: "Premium"
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "customer1", "customer2" ] }
> 
> // Sales Collection (Fact)
> db.sales.insertMany([
...   {
...     sales_id: ObjectId(),
...     product_id: "product1",
...     time_id: "time1",
...     store_id: "store1",
...     customer_id: "customer1",
...     sales_amount: 1200,
...     quantity_sold: 1,
...     discount_applied: 0
...   },
...   {
...     sales_id: ObjectId(),
...     product_id: "product2",
...     time_id: "time2",
...     store_id: "store2",
...     customer_id: "customer2",
...     sales_amount: 760,
...     quantity_sold: 1,
...     discount_applied: 40
...   }
... ]);
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68cbdcec778348f61e4869c4"),
		ObjectId("68cbdcec778348f61e4869c5")
	]
}
> db.sales.aggregate([
...   {
...     $lookup: {
...       from: "products",
...       localField: "product_id",
...       foreignField: "_id",
...       as: "product_info"
...     }
...   },
...   { $unwind: "$product_info" },
...   {
...     $project: {
...       sales_amount: 1,
...       quantity_sold: 1,
...       discount_applied: 1,
...       "product_info.product_name": 1,
...       "product_info.category": 1,
...       "product_info.brand": 1
...     }
...   }
... ]).pretty();
{
	"_id" : ObjectId("68cbdcec778348f61e4869c4"),
	"sales_amount" : 1200,
	"quantity_sold" : 1,
	"discount_applied" : 0,
	"product_info" : {
		"product_name" : "Laptop",
		"category" : "Electronics",
		"brand" : "TechBrand"
	}
}
{
	"_id" : ObjectId("68cbdcec778348f61e4869c5"),
	"sales_amount" : 760,
	"quantity_sold" : 1,
	"discount_applied" : 40,
	"product_info" : {
		"product_name" : "Smartphone",
		"category" : "Electronics",
		"brand" : "PhoneBrand"
	}
}
> db.sales.aggregate([
...   {
...     $group: {
...       _id: "$store_id",
...       total_sales: { $sum: "$sales_amount" },
...       total_quantity: { $sum: "$quantity_sold" }
...     }
...   },
...   {
...     $lookup: {
...       from: "stores",
...       localField: "_id",
...       foreignField: "_id",
...       as: "store_info"
...     }
...   },
...   { $unwind: "$store_info" },
...   {
...     $project: {
...       store_name: "$store_info.store_name",
...       total_sales: 1,
...       total_quantity: 1
...     }
...   }
... ]).pretty();
{
	"_id" : "store2",
	"total_sales" : 760,
	"total_quantity" : 1,
	"store_name" : "Downtown Store"
}
{
	"_id" : "store1",
	"total_sales" : 1200,
	"total_quantity" : 1,
	"store_name" : "Main Street Store"
}
> db.sales.aggregate([
...   {
...     $lookup: {
...       from: "customers",
...       localField: "customer_id",
...       foreignField: "_id",
...       as: "customer_info"
...     }
...   },
...   { $unwind: "$customer_info" },
...   {
...     $lookup: {
...       from: "time",
...       localField: "time_id",
...       foreignField: "_id",
...       as: "time_info"
...     }
...   },
...   { $unwind: "$time_info" },
...   {
...     $project: {
...       sales_amount: 1,
...       quantity_sold: 1,
...       "customer_info.customer_name": 1,
...       "customer_info.gender": 1,
...       "time_info.date": 1
...     }
...   }
... ]).pretty();
{
	"_id" : ObjectId("68cbdcec778348f61e4869c4"),
	"sales_amount" : 1200,
	"quantity_sold" : 1,
	"customer_info" : {
		"customer_name" : "Amit Sharma",
		"gender" : "Male"
	},
	"time_info" : {
		"date" : "2025-09-18"
	}
}
{
	"_id" : ObjectId("68cbdcec778348f61e4869c5"),
	"sales_amount" : 760,
	"quantity_sold" : 1,
	"customer_info" : {
		"customer_name" : "Avani Patil",
		"gender" : "Female"
	},
	"time_info" : {
		"date" : "2025-09-19"
	}
}

