
> use retailDB_snowflake;
switched to db retailDB_snowflake


> // Brands

> db.brands.insertMany([
...   { _id: "brand1", brand_name: "TechBrand" },
...   { _id: "brand2", brand_name: "PhoneBrand" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "brand1", "brand2" ] }


> // Categories

> db.categories.insertMany([
...   { _id: "cat1", category_name: "Electronics" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "cat1" ] }


> // Subcategories

> db.subcategories.insertMany([
...   { _id: "subcat1", subcategory_name: "Computers", category_id: "cat1" },
...   { _id: "subcat2", subcategory_name: "Mobile Phones", category_id: "cat1" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "subcat1", "subcat2" ] }


> // Products

> db.products.insertMany([
...   {
...     _id: "product1",
...     product_name: "Laptop",
...     brand_id: "brand1",
...     subcategory_id: "subcat1",
...     price: 1200
...   },
...   {
...     _id: "product2",
...     product_name: "Smartphone",
...     brand_id: "brand2",
...     subcategory_id: "subcat2",
...     price: 800
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "product1", "product2" ] }


> // Months

> db.months.insertMany([
...   { _id: "month9", month_name: "September", quarter: 3 }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "month9" ] }


> // Time

> db.time.insertMany([
...   {
...     _id: "time1",
...     date: "2025-09-18",
...     day: 18,
...     month_id: "month9",
...     year: 2025
...   },
...   {
...     _id: "time2",
...     date: "2025-09-19",
...     day: 19,
...     month_id: "month9",
...     year: 2025
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "time1", "time2" ] }


> // Locations

> db.locations.insertMany([
...   {
...     _id: "loc1",
...     city: "New York",
...     state: "NY",
...     country: "USA"
...   },
...   {
...     _id: "loc2",
...     city: "Los Angeles",
...     state: "CA",
...     country: "USA"
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "loc1", "loc2" ] }


> // Stores

> db.stores.insertMany([
...   { _id: "store1", store_name: "Main Street Store", location_id: "loc1" },
...   { _id: "store2", store_name: "Downtown Store", location_id: "loc2" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "store1", "store2" ] }


> // Income Groups

> db.income_groups.insertMany([
...   { _id: "inc1", income_range: "50k-70k" },
...   { _id: "inc2", income_range: "70k-100k" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "inc1", "inc2" ] }


> // Customer Segments

> db.customer_segments.insertMany([
...   { _id: "seg1", segment_description: "Regular" },
...   { _id: "seg2", segment_description: "Premium" }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "seg1", "seg2" ] }


> // Customers

> db.customers.insertMany([
...   {
...     _id: "customer1",
...     customer_name: "John Doe",
...     gender: "Male",
...     age: 30,
...     income_group_id: "inc1",
...     customer_segment_id: "seg1"
...   },
...   {
...     _id: "customer2",
...     customer_name: "Jane Smith",
...     gender: "Female",
...     age: 25,
...     income_group_id: "inc2",
...     customer_segment_id: "seg2"
...   }
... ]);
{ "acknowledged" : true, "insertedIds" : [ "customer1", "customer2" ] }


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
		ObjectId("68cbdec96c6c994b2b4f4ba4"),
		ObjectId("68cbdec96c6c994b2b4f4ba5")
	]
}


> db.sales.aggregate([
...   // Lookup product to get subcategory_id
...   {
...     $lookup: {
...       from: "products",
...       localField: "product_id",
...       foreignField: "_id",
...       as: "product"
...     }
...   },
...   { $unwind: "$product" },
... 
...   // Lookup subcategory to get category_id
...   {
...     $lookup: {
...       from: "subcategories",
...       localField: "product.subcategory_id",
...       foreignField: "_id",
...       as: "subcategory"
...     }
...   },
...   { $unwind: "$subcategory" },
... 
...   // Lookup category to get category name
...   {
...     $lookup: {
...       from: "categories",
...       localField: "subcategory.category_id",
...       foreignField: "_id",
...       as: "category"
...     }
...   },
...   { $unwind: "$category" },
... 
...   // Group by category name and sum sales_amount
...   {
...     $group: {
...       _id: "$category.category_name",
...       total_sales: { $sum: "$sales_amount" }
...     }
...   },
... 
...   // Sort descending by total sales
...   { $sort: { total_sales: -1 } }
... ]).pretty();
{ "_id" : "Electronics", "total_sales" : 1960 }


> db.sales.aggregate([
...   {
...     $lookup: {
...       from: "customers",
...       localField: "customer_id",
...       foreignField: "_id",
...       as: "customer"
...     }
...   },
...   { $unwind: "$customer" },
... 
...   {
...     $lookup: {
...       from: "customer_segments",
...       localField: "customer.customer_segment_id",
...       foreignField: "_id",
...       as: "segment"
...     }
...   },
...   { $unwind: "$segment" },
... 
...   {
...     $group: {
...       _id: "$segment.segment_description",
...       sales_count: { $sum: 1 },
...       total_revenue: { $sum: "$sales_amount" }
...     }
...   },
... 
...   { $sort: { total_revenue: -1 } }
... ]).pretty();
{ "_id" : "Regular", "sales_count" : 1, "total_revenue" : 1200 }
{ "_id" : "Premium", "sales_count" : 1, "total_revenue" : 760 }


> db.sales.aggregate([
...   {
...     $lookup: {
...       from: "stores",
...       localField: "store_id",
...       foreignField: "_id",
...       as: "store"
...     }
...   },
...   { $unwind: "$store" },
... 
...   {
...     $lookup: {
...       from: "locations",
...       localField: "store.location_id",
...       foreignField: "_id",
...       as: "location"
...     }
...   },
...   { $unwind: "$location" },
... 
...   {
...     $group: {
...       _id: "$location.city",
...       total_sales: { $sum: "$sales_amount" },
...       total_quantity: { $sum: "$quantity_sold" }
...     }
...   },
... 
...   { $sort: { total_sales: -1 } }
... ]).pretty();
{ "_id" : "New York", "total_sales" : 1200, "total_quantity" : 1 }
{ "_id" : "Los Angeles", "total_sales" : 760, "total_quantity" : 1 }


> db.sales.aggregate([
...   {
...     $lookup: {
...       from: "time",
...       localField: "time_id",
...       foreignField: "_id",
...       as: "time"
...     }
...   },
...   { $unwind: "$time" },
... 
...   {
...     $lookup: {
...       from: "months",
...       localField: "time.month_id",
...       foreignField: "_id",
...       as: "month"
...     }
...   },
...   { $unwind: "$month" },
... 
...   {
...     $group: {
...       _id: { year: "$time.year", month: "$month.month_name" },
...       total_sales: { $sum: "$sales_amount" }
...     }
...   },
... 
...   { $sort: { "_id.year": 1, "_id.month": 1 } }
... ]).pretty();
{
	"_id" : {
		"year" : 2025,
		"month" : "September"
	},
	"total_sales" : 1960
}

