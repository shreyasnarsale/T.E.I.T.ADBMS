
student@student-ThinkCentre-M700:~$ mongo

> use companyDB
switched to db companyDB
> db.employees.insertMany([
...   { eid: 1, ename: "Amit Sharma", designation: "Analyst", hiredate: ISODate("2015-07-20"), salary: 25000, hobbies: ["cricket", "reading", "traveling"], department: "Sales" },
...   { eid: 2, ename: "Bhavna Patil", designation: "Manager", hiredate: ISODate("2016-03-15"), salary: 35000, hobbies: ["painting", "reading"], department: "HR" },
...   { eid: 3, ename: "Rahul Deshmukh", designation: "Salesman", hiredate: ISODate("2015-08-10"), salary: 9000, hobbies: ["cricket", "reading", "music"], department: "Sales" },
...   { eid: 4, ename: "Rita Mehta", designation: "Analyst", hiredate: ISODate("2017-05-25"), salary: 9500, hobbies: ["painting", "traveling"], department: "Marketing" },
...   { eid: 5, ename: "Sunil Rao", designation: "Manager", hiredate: ISODate("2014-12-30"), salary: 40000, hobbies: ["reading", "music"], department: "Production" },
...   { eid: 6, ename: "Pooja Shetty", designation: "Salesman", hiredate: ISODate("2015-11-05"), salary: 9500, hobbies: ["painting", "reading", "traveling"], department: "Sales" },
...   { eid: 7, ename: "Anish Kumar", designation: "Analyst", hiredate: ISODate("2016-09-12"), salary: 12000, hobbies: ["cricket", "reading", "painting"], department: "IT" },
...   { eid: 8, ename: "Akash Verma", designation: "Manager", hiredate: ISODate("2015-06-30"), salary: 15000, hobbies: ["music", "reading"], department: "Production" },
...   { eid: 9, ename: "Anita Singh", designation: "Salesman", hiredate: ISODate("2017-01-20"), salary: 8000, hobbies: ["reading", "traveling"], department: "Sales" },
...   { eid: 10, ename: "Sahil Joshi", designation: "Analyst", hiredate: ISODate("2016-04-18"), salary: 18000, hobbies: ["cricket", "painting"], department: "IT" }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68e791ae4676b0646eb11db3"),
		ObjectId("68e791ae4676b0646eb11db4"),
		ObjectId("68e791ae4676b0646eb11db5"),
		ObjectId("68e791ae4676b0646eb11db6"),
		ObjectId("68e791ae4676b0646eb11db7"),
		ObjectId("68e791ae4676b0646eb11db8"),
		ObjectId("68e791ae4676b0646eb11db9"),
		ObjectId("68e791ae4676b0646eb11dba"),
		ObjectId("68e791ae4676b0646eb11dbb"),
		ObjectId("68e791ae4676b0646eb11dbc")
	]
}
> db.employees.find().pretty()
{
	"_id" : ObjectId("68e791ae4676b0646eb11db3"),
	"eid" : 1,
	"ename" : "Amit Sharma",
	"designation" : "Analyst",
	"hiredate" : ISODate("2015-07-20T00:00:00Z"),
	"salary" : 25000,
	"hobbies" : [
		"cricket",
		"reading",
		"traveling"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db4"),
	"eid" : 2,
	"ename" : "Bhavna Patil",
	"designation" : "Manager",
	"hiredate" : ISODate("2016-03-15T00:00:00Z"),
	"salary" : 35000,
	"hobbies" : [
		"painting",
		"reading"
	],
	"department" : "HR"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db5"),
	"eid" : 3,
	"ename" : "Rahul Deshmukh",
	"designation" : "Salesman",
	"hiredate" : ISODate("2015-08-10T00:00:00Z"),
	"salary" : 9000,
	"hobbies" : [
		"cricket",
		"reading",
		"music"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db6"),
	"eid" : 4,
	"ename" : "Rita Mehta",
	"designation" : "Analyst",
	"hiredate" : ISODate("2017-05-25T00:00:00Z"),
	"salary" : 9500,
	"hobbies" : [
		"painting",
		"traveling"
	],
	"department" : "Marketing"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db7"),
	"eid" : 5,
	"ename" : "Sunil Rao",
	"designation" : "Manager",
	"hiredate" : ISODate("2014-12-30T00:00:00Z"),
	"salary" : 40000,
	"hobbies" : [
		"reading",
		"music"
	],
	"department" : "Production"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db8"),
	"eid" : 6,
	"ename" : "Pooja Shetty",
	"designation" : "Salesman",
	"hiredate" : ISODate("2015-11-05T00:00:00Z"),
	"salary" : 9500,
	"hobbies" : [
		"painting",
		"reading",
		"traveling"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11db9"),
	"eid" : 7,
	"ename" : "Anish Kumar",
	"designation" : "Analyst",
	"hiredate" : ISODate("2016-09-12T00:00:00Z"),
	"salary" : 12000,
	"hobbies" : [
		"cricket",
		"reading",
		"painting"
	],
	"department" : "IT"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11dba"),
	"eid" : 8,
	"ename" : "Akash Verma",
	"designation" : "Manager",
	"hiredate" : ISODate("2015-06-30T00:00:00Z"),
	"salary" : 15000,
	"hobbies" : [
		"music",
		"reading"
	],
	"department" : "Production"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11dbb"),
	"eid" : 9,
	"ename" : "Anita Singh",
	"designation" : "Salesman",
	"hiredate" : ISODate("2017-01-20T00:00:00Z"),
	"salary" : 8000,
	"hobbies" : [
		"reading",
		"traveling"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e791ae4676b0646eb11dbc"),
	"eid" : 10,
	"ename" : "Sahil Joshi",
	"designation" : "Analyst",
	"hiredate" : ISODate("2016-04-18T00:00:00Z"),
	"salary" : 18000,
	"hobbies" : [
		"cricket",
		"painting"
	],
	"department" : "IT"
}

#MapReduce:-

> var mapSalary = function() {
...     emit(this.department, this.salary);
... };
> var reduceTotalSalary = function(dept, salaries) {
...     return Array.sum(salaries);
... };
> var reduceAvgSalary = function(dept, salaries) {
...     return Array.sum(salaries)/salaries.length;
... };
> db.employees.mapReduce(mapSalary, reduceTotalSalary, { out: "total_salary_dept" })
{
	"result" : "total_salary_dept",
	"timeMillis" : 374,
	"counts" : {
		"input" : 10,
		"emit" : 10,
		"reduce" : 3,
		"output" : 5
	},
	"ok" : 1
}
> db.total_salary_dept.find()
{ "_id" : "HR", "value" : 35000 }
{ "_id" : "IT", "value" : 30000 }
{ "_id" : "Marketing", "value" : 9500 }
{ "_id" : "Production", "value" : 55000 }
{ "_id" : "Sales", "value" : 51500 }
> db.employees.mapReduce(mapSalary, reduceAvgSalary, { out: "avg_salary_dept" })
{
	"result" : "avg_salary_dept",
	"timeMillis" : 362,
	"counts" : {
		"input" : 10,
		"emit" : 10,
		"reduce" : 3,
		"output" : 5
	},
	"ok" : 1
}
> db.avg_salary_dept.find()
{ "_id" : "HR", "value" : 35000 }
{ "_id" : "IT", "value" : 15000 }
{ "_id" : "Marketing", "value" : 9500 }
{ "_id" : "Production", "value" : 27500 }
{ "_id" : "Sales", "value" : 12875 }

#Aggregation:-

> db.employees.aggregate([
...     {
...         $group: {
...             _id: "$designation",
...             totalSalary: { $sum: "$salary" },
...             avgSalary: { $avg: "$salary" }
...         }
...     }
... ])
{ "_id" : "Salesman", "totalSalary" : 26500, "avgSalary" : 8833.333333333334 }
{ "_id" : "Manager", "totalSalary" : 90000, "avgSalary" : 30000 }
{ "_id" : "Analyst", "totalSalary" : 64500, "avgSalary" : 16125 }

#Indexing:-

> db.employees.createIndex({ department: 1 })
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}
> db.employees.find({ department: "Sales" }).explain("executionStats")
{
	"queryPlanner" : {
		"plannerVersion" : 1,
		"namespace" : "companyDB.employees",
		"indexFilterSet" : false,
		"parsedQuery" : {
			"department" : {
				"$eq" : "Sales"
			}
		},
		"winningPlan" : {
			"stage" : "FETCH",
			"inputStage" : {
				"stage" : "IXSCAN",
				"keyPattern" : {
					"department" : 1
				},
				"indexName" : "department_1",
				"isMultiKey" : false,
				"multiKeyPaths" : {
					"department" : [ ]
				},
				"isUnique" : false,
				"isSparse" : false,
				"isPartial" : false,
				"indexVersion" : 2,
				"direction" : "forward",
				"indexBounds" : {
					"department" : [
						"[\"Sales\", \"Sales\"]"
					]
				}
			}
		},
		"rejectedPlans" : [ ]
	},
	"executionStats" : {
		"executionSuccess" : true,
		"nReturned" : 4,
		"executionTimeMillis" : 0,
		"totalKeysExamined" : 4,
		"totalDocsExamined" : 4,
		"executionStages" : {
			"stage" : "FETCH",
			"nReturned" : 4,
			"executionTimeMillisEstimate" : 0,
			"works" : 5,
			"advanced" : 4,
			"needTime" : 0,
			"needYield" : 0,
			"saveState" : 0,
			"restoreState" : 0,
			"isEOF" : 1,
			"invalidates" : 0,
			"docsExamined" : 4,
			"alreadyHasObj" : 0,
			"inputStage" : {
				"stage" : "IXSCAN",
				"nReturned" : 4,
				"executionTimeMillisEstimate" : 0,
				"works" : 5,
				"advanced" : 4,
				"needTime" : 0,
				"needYield" : 0,
				"saveState" : 0,
				"restoreState" : 0,
				"isEOF" : 1,
				"invalidates" : 0,
				"keyPattern" : {
					"department" : 1
				},
				"indexName" : "department_1",
				"isMultiKey" : false,
				"multiKeyPaths" : {
					"department" : [ ]
				},
				"isUnique" : false,
				"isSparse" : false,
				"isPartial" : false,
				"indexVersion" : 2,
				"direction" : "forward",
				"indexBounds" : {
					"department" : [
						"[\"Sales\", \"Sales\"]"
					]
				},
				"keysExamined" : 4,
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
> db.employees.createIndex({ department: 1, salary: -1 })
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 2,
	"numIndexesAfter" : 3,
	"ok" : 1
}
> db.employees.dropIndex("department_1")
{ "nIndexesWas" : 3, "ok" : 1 }
