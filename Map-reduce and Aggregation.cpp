Implement Map-reduce and aggregation, indexing with suitable example in MongoDB.
Demonstrate the following:
			1)Aggregation framework
		        2)Create and drop different types of indexes and explain () to show the advantage of the indexes.



> use salesDB
switched to db salesDB
> db.sales.insertMany([
...   { item: "apple", quantity: 5, price: 10 },
...   { item: "banana", quantity: 10, price: 5 },
...   { item: "apple", quantity: 7, price: 10 },
...   { item: "banana", quantity: 3, price: 5 }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68cbe7571e350fac6dc5c7a8"),
		ObjectId("68cbe7571e350fac6dc5c7a9"),
		ObjectId("68cbe7571e350fac6dc5c7aa"),
		ObjectId("68cbe7571e350fac6dc5c7ab")
	]
}

> var mapFunction = function() {
...   emit(this.item, this.quantity);
... };
> 
> var reduceFunction = function(key, values) {
...   return Array.sum(values);
... };
> 
> db.sales.mapReduce(
...   mapFunction,
...   reduceFunction,
...   { out: "total_quantity_per_item" }
... )
{
	"result" : "total_quantity_per_item",
	"timeMillis" : 516,
	"counts" : {
		"input" : 4,
		"emit" : 4,
		"reduce" : 2,
		"output" : 2
	},
	"ok" : 1
}
> db.total_quantity_per_item.find()
{ "_id" : "apple", "value" : 12 }
{ "_id" : "banana", "value" : 13 }
> db.sales.aggregate([
...   {
...     $group: {
...       _id: "$item",
...       totalQuantity: { $sum: "$quantity" }
...     }
...   }
... ])
{ "_id" : "banana", "totalQuantity" : 13 }
{ "_id" : "apple", "totalQuantity" : 12 }
> db.sales.createIndex({ item: 1 })
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}
> db.sales.dropIndexes()
{
	"nIndexesWas" : 2,
	"msg" : "non-_id indexes dropped for collection",
	"ok" : 1
}
> db.sales.find({ item: "apple" }).explain("executionStats")
{
	"queryPlanner" : {
		"plannerVersion" : 1,
		"namespace" : "salesDB.sales",
		"indexFilterSet" : false,
		"parsedQuery" : {
			"item" : {
				"$eq" : "apple"
			}
		},
		"winningPlan" : {
			"stage" : "COLLSCAN",
			"filter" : {
				"item" : {
					"$eq" : "apple"
				}
			},
			"direction" : "forward"
		},
		"rejectedPlans" : [ ]
	},
	"executionStats" : {
		"executionSuccess" : true,
		"nReturned" : 2,
		"executionTimeMillis" : 0,
		"totalKeysExamined" : 0,
		"totalDocsExamined" : 4,
		"executionStages" : {
			"stage" : "COLLSCAN",
			"filter" : {
				"item" : {
					"$eq" : "apple"
				}
			},
			"nReturned" : 2,
			"executionTimeMillisEstimate" : 0,
			"works" : 6,
			"advanced" : 2,
			"needTime" : 3,
			"needYield" : 0,
			"saveState" : 0,
			"restoreState" : 0,
			"isEOF" : 1,
			"invalidates" : 0,
			"direction" : "forward",
			"docsExamined" : 4
		}
	},
	"serverInfo" : {
		"host" : "student-ThinkCentre-M700",
		"port" : 27017,
		"version" : "3.6.8",
		"gitVersion" : "8e540c0b6db93ce994cc548f000900bdc740f80a"
	},
	"ok" : 1
}
> db.sales.createIndex({ item: 1 })
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}
> db.sales.find({ item: "apple" }).explain("executionStats")
{
	"queryPlanner" : {
		"plannerVersion" : 1,
		"namespace" : "salesDB.sales",
		"indexFilterSet" : false,
		"parsedQuery" : {
			"item" : {
				"$eq" : "apple"
			}
		},
		"winningPlan" : {
			"stage" : "FETCH",
			"inputStage" : {
				"stage" : "IXSCAN",
				"keyPattern" : {
					"item" : 1
				},
				"indexName" : "item_1",
				"isMultiKey" : false,
				"multiKeyPaths" : {
					"item" : [ ]
				},
				"isUnique" : false,
				"isSparse" : false,
				"isPartial" : false,
				"indexVersion" : 2,
				"direction" : "forward",
				"indexBounds" : {
					"item" : [
						"[\"apple\", \"apple\"]"
					]
				}
			}
		},
		"rejectedPlans" : [ ]
	},
	"executionStats" : {
		"executionSuccess" : true,
		"nReturned" : 2,
		"executionTimeMillis" : 0,
		"totalKeysExamined" : 2,
		"totalDocsExamined" : 2,
		"executionStages" : {
			"stage" : "FETCH",
			"nReturned" : 2,
			"executionTimeMillisEstimate" : 0,
			"works" : 3,
			"advanced" : 2,
			"needTime" : 0,
			"needYield" : 0,
			"saveState" : 0,
			"restoreState" : 0,
			"isEOF" : 1,
			"invalidates" : 0,
			"docsExamined" : 2,
			"alreadyHasObj" : 0,
			"inputStage" : {
				"stage" : "IXSCAN",
				"nReturned" : 2,
				"executionTimeMillisEstimate" : 0,
				"works" : 3,
				"advanced" : 2,
				"needTime" : 0,
				"needYield" : 0,
				"saveState" : 0,
				"restoreState" : 0,
				"isEOF" : 1,
				"invalidates" : 0,
				"keyPattern" : {
					"item" : 1
				},
				"indexName" : "item_1",
				"isMultiKey" : false,
				"multiKeyPaths" : {
					"item" : [ ]
				},
				"isUnique" : false,
				"isSparse" : false,
				"isPartial" : false,
				"indexVersion" : 2,
				"direction" : "forward",
				"indexBounds" : {
					"item" : [
						"[\"apple\", \"apple\"]"
					]
				},
				"keysExamined" : 2,
				"seeks" : 1,
				"dupsTested" : 0,
				"dupsDropped" : 0,
				"seenInvalidated" : 0
			}
		}
	},
	"serverInfo" : {
		"host" : "student-ThinkCentre-M700",
		"port" : 27017,
		"version" : "3.6.8",
		"gitVersion" : "8e540c0b6db93ce994cc548f000900bdc740f80a"
	},
	"ok" : 1
}
> db.sales.dropIndex("item_1")
{ "nIndexesWas" : 2, "ok" : 1 }
> 

