student@student-ThinkCentre-M700:~$ mongo

> use empDB
switched to db empDB
> db.emp.insertMany([
...   { emp_id: 1, name: "Amit", city: "Pune", salary: 5000 },
...   { emp_id: 2, name: "Sumit", city: "Delhi", salary: 10000 },
...   { emp_id: 3, name: "Mit", city: "Pune", salary: 7000 },
...   { emp_id: 4, name: "Ajit", city: "Mumbai", salary: 4000 },
...   { emp_id: 5, name: "Ranjit", city: "Mumbai", salary: 3000 }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68e79617e2b507b659bce35a"),
		ObjectId("68e79617e2b507b659bce35b"),
		ObjectId("68e79617e2b507b659bce35c"),
		ObjectId("68e79617e2b507b659bce35d"),
		ObjectId("68e79617e2b507b659bce35e")
	]
}
> db.emp.find()
{ "_id" : ObjectId("68e79617e2b507b659bce35a"), "emp_id" : 1, "name" : "Amit", "city" : "Pune", "salary" : 5000 }
{ "_id" : ObjectId("68e79617e2b507b659bce35b"), "emp_id" : 2, "name" : "Sumit", "city" : "Delhi", "salary" : 10000 }
{ "_id" : ObjectId("68e79617e2b507b659bce35c"), "emp_id" : 3, "name" : "Mit", "city" : "Pune", "salary" : 7000 }
{ "_id" : ObjectId("68e79617e2b507b659bce35d"), "emp_id" : 4, "name" : "Ajit", "city" : "Mumbai", "salary" : 4000 }
{ "_id" : ObjectId("68e79617e2b507b659bce35e"), "emp_id" : 5, "name" : "Ranjit", "city" : "Mumbai", "salary" : 3000 }
> db.emp.aggregate([
...   { $group: { _id: null, TotalSalary: { $sum: "$salary" } } }
... ])
{ "_id" : null, "TotalSalary" : 29000 }
> db.emp.aggregate([
...   { $group: { _id: "$city", TotalSalary: { $sum: "$salary" } } }
... ])
{ "_id" : "Mumbai", "TotalSalary" : 7000 }
{ "_id" : "Delhi", "TotalSalary" : 10000 }
{ "_id" : "Pune", "TotalSalary" : 12000 }
> db.emp.aggregate([
...   { $group: { _id: "$city", MinimumSalary: { $min: "$salary" } } }
... ])
{ "_id" : "Mumbai", "MinimumSalary" : 3000 }
{ "_id" : "Delhi", "MinimumSalary" : 10000 }
{ "_id" : "Pune", "MinimumSalary" : 5000 }
> db.emp.aggregate([
...   { $group: { _id: "$city", MaximumSalary: { $max: "$salary" } } }
... ])
{ "_id" : "Mumbai", "MaximumSalary" : 4000 }
{ "_id" : "Delhi", "MaximumSalary" : 10000 }
{ "_id" : "Pune", "MaximumSalary" : 7000 }
> db.emp.aggregate([
...   { $group: { _id: "$city", EmployeeCount: { $sum: 1 } } }
... ])
{ "_id" : "Mumbai", "EmployeeCount" : 2 }
{ "_id" : "Delhi", "EmployeeCount" : 1 }
{ "_id" : "Pune", "EmployeeCount" : 2 }
> db.emp.aggregate([
...   { $group: { _id: null, TotalEmployees: { $sum: 1 } } }
... ])
{ "_id" : null, "TotalEmployees" : 5 }
> db.emp.aggregate([
...   { $group: { _id: "$city", AverageSalary: { $avg: "$salary" } } }
... ])
{ "_id" : "Mumbai", "AverageSalary" : 3500 }
{ "_id" : "Delhi", "AverageSalary" : 10000 }
{ "_id" : "Pune", "AverageSalary" : 6000 }
> db.emp.aggregate([
...   { $match: { city: 'Pune' } },
...   { $group: { _id: null, TotalSalary: { $sum: "$salary" } } }
... ])
{ "_id" : null, "TotalSalary" : 12000 }
> db.emp.aggregate([
...   { $match: { city: 'Pune' } },
...   { $group: { _id: "$city", TotalSalary: { $sum: "$salary" } } }
... ])
{ "_id" : "Pune", "TotalSalary" : 12000 }
> db.emp.aggregate([
...   { $group: { _id: null, EmployeeCount: { $sum: 1 } } }
... ])
{ "_id" : null, "EmployeeCount" : 5 }
> db.emp.aggregate([
...   { $group: { _id: "$city", EmployeeCount: { $sum: 1 } } }
... ])
{ "_id" : "Mumbai", "EmployeeCount" : 2 }
{ "_id" : "Delhi", "EmployeeCount" : 1 }
{ "_id" : "Pune", "EmployeeCount" : 2 }

> db.emp.aggregate([
...   { $match: { city: "Pune" } },
...   { $group: { _id: null, TotalSalary: { $sum: "$salary" } } }
... ])
{ "_id" : null, "TotalSalary" : 12000 }


