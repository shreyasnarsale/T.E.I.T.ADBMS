student@student-ThinkCentre-M700:~$ mongo

> show dbs
EMP                 0.000GB
Info                0.000GB
admin               0.000GB
config              0.000GB
local               0.000GB
myDatabase          0.000GB
retailDB            0.000GB
retailDB_snowflake  0.000GB
test                0.000GB
yourDatabase        0.000GB

> use company
switched to db company
> db.employee.insertOne({
...   eid: 1,
...   ename: "Amit Sharma",
...   designation: "Manager",
...   hiredate: new Date("2015-05-10"),
...   salary: 25000,
...   hobbies: ["reading", "traveling", "painting"],
...   department: "Sales"
... })
{
	"acknowledged" : true,
	"insertedId" : ObjectId("68e785464a2335a6530f9952")
}
> db.employee.insertMany([
...   { eid: 2, ename: "Sneha Patil", designation: "Analyst", hiredate: new Date("2016-01-15"), salary: 12000, hobbies: ["music", "reading", "gardening"], department: "HR" },
...   { eid: 3, ename: "Rahul Deshmukh", designation: "Salesman", hiredate: new Date("2015-07-20"), salary: 9000, hobbies: ["cricket", "reading", "traveling"], department: "Sales" },
...   { eid: 4, ename: "Priya Joshi", designation: "Developer", hiredate: new Date("2014-12-10"), salary: 18000, hobbies: ["painting", "reading", "music"], department: "IT" },
...   { eid: 5, ename: "Anil Kumar", designation: "Manager", hiredate: new Date("2013-11-05"), salary: 30000, hobbies: ["reading", "cooking", "traveling"], department: "Production" },
...   { eid: 6, ename: "Suresh Singh", designation: "Analyst", hiredate: new Date("2015-10-12"), salary: 15000, hobbies: ["reading", "painting", "cycling"], department: "Finance" },
...   { eid: 7, ename: "Rita Mehta", designation: "Salesman", hiredate: new Date("2015-09-05"), salary: 9500, hobbies: ["reading", "music", "traveling"], department: "Sales" },
...   { eid: 8, ename: "Nikhil Rane", designation: "Developer", hiredate: new Date("2016-03-25"), salary: 17000, hobbies: ["sports", "reading", "chess"], department: "IT" },
...   { eid: 9, ename: "Asha Nair", designation: "Clerk", hiredate: new Date("2015-11-30"), salary: 8000, hobbies: ["reading", "painting", "music"], department: "Admin" },
...   { eid: 10, ename: "Deepak Sahu", designation: "Technician", hiredate: new Date("2015-06-25"), salary: 11000, hobbies: ["cycling", "reading", "gaming"], department: "Production" },
...   { eid: 11, ename: "Pooja Shetty", designation: "Salesman", hiredate: new Date("2015-07-15"), salary: 9500, hobbies: ["reading", "dance", "painting"], department: "Sales" },
...   { eid: 12, ename: "Akash Shinde", designation: "Developer", hiredate: new Date("2016-05-12"), salary: 16000, hobbies: ["reading", "traveling", "gaming"], department: "IT" },
...   { eid: 13, ename: "Ramesh Patil", designation: "Manager", hiredate: new Date("2012-09-25"), salary: 28000, hobbies: ["cooking", "reading", "gardening"], department: "Finance" },
...   { eid: 14, ename: "Manisha Kale", designation: "HR Executive", hiredate: new Date("2015-08-18"), salary: 13000, hobbies: ["reading", "painting", "yoga"], department: "HR" },
...   { eid: 15, ename: "Ashwin Soni", designation: "Analyst", hiredate: new Date("2015-12-05"), salary: 14000, hobbies: ["reading", "painting", "traveling"], department: "Finance" }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68e785564a2335a6530f9953"),
		ObjectId("68e785564a2335a6530f9954"),
		ObjectId("68e785564a2335a6530f9955"),
		ObjectId("68e785564a2335a6530f9956"),
		ObjectId("68e785564a2335a6530f9957"),
		ObjectId("68e785564a2335a6530f9958"),
		ObjectId("68e785564a2335a6530f9959"),
		ObjectId("68e785564a2335a6530f995a"),
		ObjectId("68e785564a2335a6530f995b"),
		ObjectId("68e785564a2335a6530f995c"),
		ObjectId("68e785564a2335a6530f995d"),
		ObjectId("68e785564a2335a6530f995e"),
		ObjectId("68e785564a2335a6530f995f"),
		ObjectId("68e785564a2335a6530f9960")
	]
}

> db.employee.find().pretty()
{
	"_id" : ObjectId("68e785464a2335a6530f9952"),
	"eid" : 1,
	"ename" : "Amit Sharma",
	"designation" : "Manager",
	"hiredate" : ISODate("2015-05-10T00:00:00Z"),
	"salary" : 25000,
	"hobbies" : [
		"reading",
		"traveling",
		"painting"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9953"),
	"eid" : 2,
	"ename" : "Sneha Patil",
	"designation" : "Analyst",
	"hiredate" : ISODate("2016-01-15T00:00:00Z"),
	"salary" : 12000,
	"hobbies" : [
		"music",
		"reading",
		"gardening"
	],
	"department" : "HR"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9954"),
	"eid" : 3,
	"ename" : "Rahul Deshmukh",
	"designation" : "Salesman",
	"hiredate" : ISODate("2015-07-20T00:00:00Z"),
	"salary" : 9000,
	"hobbies" : [
		"cricket",
		"reading",
		"traveling"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9955"),
	"eid" : 4,
	"ename" : "Priya Joshi",
	"designation" : "Developer",
	"hiredate" : ISODate("2014-12-10T00:00:00Z"),
	"salary" : 18000,
	"hobbies" : [
		"painting",
		"reading",
		"music"
	],
	"department" : "IT"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9956"),
	"eid" : 5,
	"ename" : "Anil Kumar",
	"designation" : "Manager",
	"hiredate" : ISODate("2013-11-05T00:00:00Z"),
	"salary" : 30000,
	"hobbies" : [
		"reading",
		"cooking",
		"traveling"
	],
	"department" : "Production"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9957"),
	"eid" : 6,
	"ename" : "Suresh Singh",
	"designation" : "Analyst",
	"hiredate" : ISODate("2015-10-12T00:00:00Z"),
	"salary" : 15000,
	"hobbies" : [
		"reading",
		"painting",
		"cycling"
	],
	"department" : "Finance"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9958"),
	"eid" : 7,
	"ename" : "Rita Mehta",
	"designation" : "Salesman",
	"hiredate" : ISODate("2015-09-05T00:00:00Z"),
	"salary" : 9500,
	"hobbies" : [
		"reading",
		"music",
		"traveling"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9959"),
	"eid" : 8,
	"ename" : "Nikhil Rane",
	"designation" : "Developer",
	"hiredate" : ISODate("2016-03-25T00:00:00Z"),
	"salary" : 17000,
	"hobbies" : [
		"sports",
		"reading",
		"chess"
	],
	"department" : "IT"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995a"),
	"eid" : 9,
	"ename" : "Asha Nair",
	"designation" : "Clerk",
	"hiredate" : ISODate("2015-11-30T00:00:00Z"),
	"salary" : 8000,
	"hobbies" : [
		"reading",
		"painting",
		"music"
	],
	"department" : "Admin"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995b"),
	"eid" : 10,
	"ename" : "Deepak Sahu",
	"designation" : "Technician",
	"hiredate" : ISODate("2015-06-25T00:00:00Z"),
	"salary" : 11000,
	"hobbies" : [
		"cycling",
		"reading",
		"gaming"
	],
	"department" : "Production"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995c"),
	"eid" : 11,
	"ename" : "Pooja Shetty",
	"designation" : "Salesman",
	"hiredate" : ISODate("2015-07-15T00:00:00Z"),
	"salary" : 9500,
	"hobbies" : [
		"reading",
		"dance",
		"painting"
	],
	"department" : "Sales"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995d"),
	"eid" : 12,
	"ename" : "Akash Shinde",
	"designation" : "Developer",
	"hiredate" : ISODate("2016-05-12T00:00:00Z"),
	"salary" : 16000,
	"hobbies" : [
		"reading",
		"traveling",
		"gaming"
	],
	"department" : "IT"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995e"),
	"eid" : 13,
	"ename" : "Ramesh Patil",
	"designation" : "Manager",
	"hiredate" : ISODate("2012-09-25T00:00:00Z"),
	"salary" : 28000,
	"hobbies" : [
		"cooking",
		"reading",
		"gardening"
	],
	"department" : "Finance"
}
{
	"_id" : ObjectId("68e785564a2335a6530f995f"),
	"eid" : 14,
	"ename" : "Manisha Kale",
	"designation" : "HR Executive",
	"hiredate" : ISODate("2015-08-18T00:00:00Z"),
	"salary" : 13000,
	"hobbies" : [
		"reading",
		"painting",
		"yoga"
	],
	"department" : "HR"
}
{
	"_id" : ObjectId("68e785564a2335a6530f9960"),
	"eid" : 15,
	"ename" : "Ashwin Soni",
	"designation" : "Analyst",
	"hiredate" : ISODate("2015-12-05T00:00:00Z"),
	"salary" : 14000,
	"hobbies" : [
		"reading",
		"painting",
		"traveling"
	],
	"department" : "Finance"
}

a) List the names of analysts and salesmen.
> db.employee.find({ designation: { $in: ["Analyst", "Salesman"] } }, { ename: 1, _id: 0 })
{ "ename" : "Sneha Patil" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Ashwin Soni" }

b) List the eid,ename and salary from employee collection.
> db.employee.find({}, { eid: 1, ename: 1, salary: 1, _id: 0 })
{ "eid" : 1, "ename" : "Amit Sharma", "salary" : 25000 }
{ "eid" : 2, "ename" : "Sneha Patil", "salary" : 12000 }
{ "eid" : 3, "ename" : "Rahul Deshmukh", "salary" : 9000 }
{ "eid" : 4, "ename" : "Priya Joshi", "salary" : 18000 }
{ "eid" : 5, "ename" : "Anil Kumar", "salary" : 30000 }
{ "eid" : 6, "ename" : "Suresh Singh", "salary" : 15000 }
{ "eid" : 7, "ename" : "Rita Mehta", "salary" : 9500 }
{ "eid" : 8, "ename" : "Nikhil Rane", "salary" : 17000 }
{ "eid" : 9, "ename" : "Asha Nair", "salary" : 8000 }
{ "eid" : 10, "ename" : "Deepak Sahu", "salary" : 11000 }
{ "eid" : 11, "ename" : "Pooja Shetty", "salary" : 9500 }
{ "eid" : 12, "ename" : "Akash Shinde", "salary" : 16000 }
{ "eid" : 13, "ename" : "Ramesh Patil", "salary" : 28000 }
{ "eid" : 14, "ename" : "Manisha Kale", "salary" : 13000 }
{ "eid" : 15, "ename" : "Ashwin Soni", "salary" : 14000 }

c) List names of employees who are not managers.
> db.employee.find({ designation: { $ne: "Manager" } }, { ename: 1, _id: 0 })
{ "ename" : "Sneha Patil" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Nikhil Rane" }
{ "ename" : "Asha Nair" }
{ "ename" : "Deepak Sahu" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Akash Shinde" }
{ "ename" : "Manisha Kale" }
{ "ename" : "Ashwin Soni" }

d) List the names of employees whose employee numbers are 1,3,7,9.
> db.employee.find({ eid: { $in: [1, 3, 7, 9] } }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Asha Nair" }

e) List the names of all employees those having reading as a secound hobby.
> db.employee.find({ "hobbies.1": "reading" }, { ename: 1, _id: 0 })
{ "ename" : "Sneha Patil" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Nikhil Rane" }
{ "ename" : "Deepak Sahu" }
{ "ename" : "Ramesh Patil" }

f) List employee names for those who have joined between 30 June and 31 Dec 2015.
> db.employee.find({ hiredate: { $gte: new Date("2015-06-30"), $lte: new Date("2015-12-31") } }, { ename: 1, _id: 0 })
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Asha Nair" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Manisha Kale" }
{ "ename" : "Ashwin Soni" }

g) List the different designations in the company.
> db.employee.distinct("designation")
[
	"Manager",
	"Analyst",
	"Salesman",
	"Developer",
	"Clerk",
	"Technician",
	"HR Executive"
]

h) List the eid,ename,salary of all employees whose salary is less than 10000.
> db.employee.find({ salary: { $lt: 10000 } }, { eid: 1, ename: 1, salary: 1, _id: 0 })
{ "eid" : 3, "ename" : "Rahul Deshmukh", "salary" : 9000 }
{ "eid" : 7, "ename" : "Rita Mehta", "salary" : 9500 }
{ "eid" : 9, "ename" : "Asha Nair", "salary" : 8000 }
{ "eid" : 11, "ename" : "Pooja Shetty", "salary" : 9500 }

i) List the name and designation of the employee who works in production department.
> db.employee.find({ department: "Production" }, { ename: 1, designation: 1, _id: 0 })
{ "ename" : "Anil Kumar", "designation" : "Manager" }
{ "ename" : "Deepak Sahu", "designation" : "Technician" }

j) List the all employees whose name start with "A" letter.
> db.employee.find({ ename: /^A/ }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Anil Kumar" }
{ "ename" : "Asha Nair" }
{ "ename" : "Akash Shinde" }
{ "ename" : "Ashwin Soni" }

k) List the all employees whose name containing "sh" string.
> db.employee.find({ ename: /sh/i }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Asha Nair" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Akash Shinde" }
{ "ename" : "Ramesh Patil" }
{ "ename" : "Manisha Kale" }
{ "ename" : "Ashwin Soni" }

l) List the all employees whose names either start or end with “S”.
> db.employee.find({ $or: [ { ename: /^S/i }, { ename: /S$/i } ] }, { ename: 1, _id: 0 })
{ "ename" : "Sneha Patil" }
{ "ename" : "Suresh Singh" }

m) List the names of employees whose department is not HR.
> db.employee.find({ department: { $ne: "HR" } }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Anil Kumar" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Nikhil Rane" }
{ "ename" : "Asha Nair" }
{ "ename" : "Deepak Sahu" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Akash Shinde" }
{ "ename" : "Ramesh Patil" }
{ "ename" : "Ashwin Soni" }

n) List the number of employees working in sales department.
> db.employee.find({ department: "Sales" }).count()
4

o) List the number of designations available in the EMP collections.
> db.employee.distinct("designation").length
7

p) List the eid,ename,salary of all employees whose salary in between 10000 to 20000.
> db.employee.find({ salary: { $gte: 10000, $lte: 20000 } }, { eid: 1, ename: 1, salary: 1, _id: 0 })
{ "eid" : 2, "ename" : "Sneha Patil", "salary" : 12000 }
{ "eid" : 4, "ename" : "Priya Joshi", "salary" : 18000 }
{ "eid" : 6, "ename" : "Suresh Singh", "salary" : 15000 }
{ "eid" : 8, "ename" : "Nikhil Rane", "salary" : 17000 }
{ "eid" : 10, "ename" : "Deepak Sahu", "salary" : 11000 }
{ "eid" : 12, "ename" : "Akash Shinde", "salary" : 16000 }
{ "eid" : 14, "ename" : "Manisha Kale", "salary" : 13000 }
{ "eid" : 15, "ename" : "Ashwin Soni", "salary" : 14000 }

q) List the eid,ename of all employees whose salary is gretter than or equal to 15000.
> db.employee.find({ salary: { $gte: 15000 } }, { eid: 1, ename: 1, _id: 0 })
{ "eid" : 1, "ename" : "Amit Sharma" }
{ "eid" : 4, "ename" : "Priya Joshi" }
{ "eid" : 5, "ename" : "Anil Kumar" }
{ "eid" : 6, "ename" : "Suresh Singh" }
{ "eid" : 8, "ename" : "Nikhil Rane" }
{ "eid" : 12, "ename" : "Akash Shinde" }
{ "eid" : 13, "ename" : "Ramesh Patil" }

r) List details of employees whose department is Sales and salary is 10000.
> db.employee.find({ department: "Sales" }, { eid: 1, ename: 1, salary: 1, _id: 0 })
{ "eid" : 1, "ename" : "Amit Sharma", "salary" : 25000 }
{ "eid" : 3, "ename" : "Rahul Deshmukh", "salary" : 9000 }
{ "eid" : 7, "ename" : "Rita Mehta", "salary" : 9500 }
{ "eid" : 11, "ename" : "Pooja Shetty", "salary" : 9500 }

s) List the names of employees those having reading and painting hobbies.
> db.employee.find({ hobbies: { $all: ["reading", "painting"] } }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Asha Nair" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Manisha Kale" }
{ "ename" : "Ashwin Soni" }

t) List the first hobby of all employees from the employee collection.
> db.employee.find({}, { ename: 1, "hobbies.0": 1, _id: 0 })
{ "ename" : "Amit Sharma", "hobbies" : [ ] }
{ "ename" : "Sneha Patil", "hobbies" : [ ] }
{ "ename" : "Rahul Deshmukh", "hobbies" : [ ] }
{ "ename" : "Priya Joshi", "hobbies" : [ ] }
{ "ename" : "Anil Kumar", "hobbies" : [ ] }
{ "ename" : "Suresh Singh", "hobbies" : [ ] }
{ "ename" : "Rita Mehta", "hobbies" : [ ] }
{ "ename" : "Nikhil Rane", "hobbies" : [ ] }
{ "ename" : "Asha Nair", "hobbies" : [ ] }
{ "ename" : "Deepak Sahu", "hobbies" : [ ] }
{ "ename" : "Pooja Shetty", "hobbies" : [ ] }
{ "ename" : "Akash Shinde", "hobbies" : [ ] }
{ "ename" : "Ramesh Patil", "hobbies" : [ ] }
{ "ename" : "Manisha Kale", "hobbies" : [ ] }
{ "ename" : "Ashwin Soni", "hobbies" : [ ] }


> db.employee.find({ hobbies: { $size: 3 } }, { ename: 1, _id: 0 })
{ "ename" : "Amit Sharma" }
{ "ename" : "Sneha Patil" }
{ "ename" : "Rahul Deshmukh" }
{ "ename" : "Priya Joshi" }
{ "ename" : "Anil Kumar" }
{ "ename" : "Suresh Singh" }
{ "ename" : "Rita Mehta" }
{ "ename" : "Nikhil Rane" }
{ "ename" : "Asha Nair" }
{ "ename" : "Deepak Sahu" }
{ "ename" : "Pooja Shetty" }
{ "ename" : "Akash Shinde" }
{ "ename" : "Ramesh Patil" }
{ "ename" : "Manisha Kale" }
{ "ename" : "Ashwin Soni" }

u) List the names of all employees those having three different hobbies.
> db.employee.find({ department: "Sales" }).count()
4


