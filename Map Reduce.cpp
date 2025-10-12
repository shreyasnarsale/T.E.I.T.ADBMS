
student@student-ThinkCentre-M700:~$ mongo

> use school
switched to db school
> db.students.insertMany([
...   { name: "Midhu", subject: "science", marks: 68 },
...   { name: "Midhu", subject: "maths", marks: 98 },
...   { name: "Midhu", subject: "sports", marks: 77 },
...   { name: "Akhil", subject: "science", marks: 67 },
...   { name: "Akhil", subject: "maths", marks: 87 },
...   { name: "Akhil", subject: "sports", marks: 89 },
...   { name: "Anish", subject: "science", marks: 67 },
...   { name: "Anish", subject: "maths", marks: 78 },
...   { name: "Anish", subject: "sports", marks: 90 }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68e78f37fc4dcd08dd230245"),
		ObjectId("68e78f37fc4dcd08dd230246"),
		ObjectId("68e78f37fc4dcd08dd230247"),
		ObjectId("68e78f37fc4dcd08dd230248"),
		ObjectId("68e78f37fc4dcd08dd230249"),
		ObjectId("68e78f37fc4dcd08dd23024a"),
		ObjectId("68e78f37fc4dcd08dd23024b"),
		ObjectId("68e78f37fc4dcd08dd23024c"),
		ObjectId("68e78f37fc4dcd08dd23024d")
	]
}
> db.students.find().pretty()
{
	"_id" : ObjectId("68e78f37fc4dcd08dd230245"),
	"name" : "Midhu",
	"subject" : "science",
	"marks" : 68
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd230246"),
	"name" : "Midhu",
	"subject" : "maths",
	"marks" : 98
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd230247"),
	"name" : "Midhu",
	"subject" : "sports",
	"marks" : 77
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd230248"),
	"name" : "Akhil",
	"subject" : "science",
	"marks" : 67
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd230249"),
	"name" : "Akhil",
	"subject" : "maths",
	"marks" : 87
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd23024a"),
	"name" : "Akhil",
	"subject" : "sports",
	"marks" : 89
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd23024b"),
	"name" : "Anish",
	"subject" : "science",
	"marks" : 67
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd23024c"),
	"name" : "Anish",
	"subject" : "maths",
	"marks" : 78
}
{
	"_id" : ObjectId("68e78f37fc4dcd08dd23024d"),
	"name" : "Anish",
	"subject" : "sports",
	"marks" : 90
}

A) MapReduce — Find Average Marks per Student
   Map function:

   Emit student name as key and marks as value.
   
> var mapFunction = function() {
...   emit(this.name, this.marks);
... };

> var reduceFunction = function(name, marksArray) {
...   var total = Array.sum(marksArray);
...   return total / marksArray.length;
... };

> db.students.mapReduce(
...   mapFunction,
...   reduceFunction,
...   { out: "avg_marks" }
... )
{
	"result" : "avg_marks",
	"timeMillis" : 521,
	"counts" : {
		"input" : 9,
		"emit" : 9,
		"reduce" : 3,
		"output" : 3
	},
	"ok" : 1
}

> db.avg_marks.find()
{ "_id" : "Akhil", "value" : 81 }
{ "_id" : "Anish", "value" : 78.33333333333333 }
{ "_id" : "Midhu", "value" : 81 }



b) MapReduce — Find Total Marks per Student


> var mapFunction2 = function() {
...   emit(this.name, this.marks);
... };

> var reduceFunction2 = function(name, marksArray) {
...   return Array.sum(marksArray);
... };

> db.students.mapReduce(
...   mapFunction2,
...   reduceFunction2,
...   { out: "total_marks" }
... )
{
	"result" : "total_marks",
	"timeMillis" : 367,
	"counts" : {
		"input" : 9,
		"emit" : 9,
		"reduce" : 3,
		"output" : 3
	},
	"ok" : 1
}

> db.total_marks.find()
{ "_id" : "Akhil", "value" : 243 }
{ "_id" : "Anish", "value" : 235 }
{ "_id" : "Midhu", "value" : 243 }



