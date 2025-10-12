student@student-ThinkCentre-M700:~$ mongo

> use customerDB
switched to db customerDB
> db.customer.insertMany([
...   { custID: "A123", Amount: 500, status: "A" },
...   { custID: "A123", Amount: 250, status: "A" },
...   { custID: "B212", Amount: 200, status: "A" },
...   { custID: "A123", Amount: 300, status: "D" }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68e78cc1ebceb26c5c931c5e"),
		ObjectId("68e78cc1ebceb26c5c931c5f"),
		ObjectId("68e78cc1ebceb26c5c931c60"),
		ObjectId("68e78cc1ebceb26c5c931c61")
	]
}
> db.customer.find().pretty()
{
	"_id" : ObjectId("68e78cc1ebceb26c5c931c5e"),
	"custID" : "A123",
	"Amount" : 500,
	"status" : "A"
}
{
	"_id" : ObjectId("68e78cc1ebceb26c5c931c5f"),
	"custID" : "A123",
	"Amount" : 250,
	"status" : "A"
}
{
	"_id" : ObjectId("68e78cc1ebceb26c5c931c60"),
	"custID" : "B212",
	"Amount" : 200,
	"status" : "A"
}
{
	"_id" : ObjectId("68e78cc1ebceb26c5c931c61"),
	"custID" : "A123",
	"Amount" : 300,
	"status" : "D"
}

a) Find the total amount of each customer.
> db.customer.aggregate([
...   { $group: { _id: "$custID", totalAmount: { $sum: "$Amount" } } }
... ])
{ "_id" : "B212", "totalAmount" : 200 }
{ "_id" : "A123", "totalAmount" : 1050 }

b) Find the total amount of each customer whose status is A.
> db.customer.aggregate([
...   { $match: { status: "A" } },
...   { $group: { _id: "$custID", totalAmount: { $sum: "$Amount" } } }
... ])
{ "_id" : "B212", "totalAmount" : 200 }
{ "_id" : "A123", "totalAmount" : 750 }

c) Find the minimum total amount of each customer whose Status is A.
> db.customer.aggregate([
...   { $match: { status: "A" } },
...   { $group: { _id: "$custID", minAmount: { $min: "$Amount" } } }
... ])
{ "_id" : "B212", "minAmount" : 200 }
{ "_id" : "A123", "minAmount" : 250 }

d) Find the maximum total amount of each customer whose Status is A.
> db.customer.aggregate([
...   { $match: { status: "A" } },
...   { $group: { _id: "$custID", maxAmount: { $max: "$Amount" } } }
... ])
{ "_id" : "B212", "maxAmount" : 200 }
{ "_id" : "A123", "maxAmount" : 500 }

e) Find the average total amount of each customer whose Status is A.
> db.customer.aggregate([
...   { $match: { status: "A" } },
...   { $group: { _id: "$custID", avgAmount: { $avg: "$Amount" } } }
... ])
{ "_id" : "B212", "avgAmount" : 200 }
{ "_id" : "A123", "avgAmount" : 375 }

f) Create index on custID.
> db.customer.createIndex({ custID: 1 })
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}

g) Execute getIndexes.
> db.customer.getIndexes()
[
	{
		"v" : 2,
		"key" : {
			"_id" : 1
		},
		"name" : "_id_",
		"ns" : "customerDB.customer"
	},
	{
		"v" : 2,
		"key" : {
			"custID" : 1
		},
		"name" : "custID_1",
		"ns" : "customerDB.customer"
	}
]

h) Drop the index created.
> db.customer.dropIndex("custID_1")
{ "nIndexesWas" : 2, "ok" : 1 }



