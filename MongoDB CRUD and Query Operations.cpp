//-----------------------------------------------------------
// 1. Use Database
//-----------------------------------------------------------
use collegeDB

//-----------------------------------------------------------
// 2. Create and Insert Documents
//-----------------------------------------------------------

// Single insert (with simple validation)
let student1 = {
    roll_no: 1,
    name: "Alice",
    age: 20,
    course: "B.Tech",
    marks: [85, 90, 88],
    status: "active"
};

if (student1.roll_no && student1.name) {
    db.students.insertOne(student1);
} else {
    print("Validation failed: Missing roll_no or name");
}

// Batch insert (insertMany)
db.students.insertMany([
    { roll_no: 2, name: "Bob", age: 21, course: "BCA", marks: [70, 75, 72], status: "active" },
    { roll_no: 3, name: "Charlie", age: 22, course: "BSc", marks: [65, 68, 70], status: "inactive" },
    { roll_no: 4, name: "David", age: 23, course: "B.Tech", marks: [95, 93, 97], status: "active" },
    { roll_no: 5, name: "Eve", age: 24, course: "BCA", marks: [80, 82, 84], status: "active" }
]);


//-----------------------------------------------------------
 db.students.find().pretty(
//-----------------------------------------------------------


//-----------------------------------------------------------
// 3. Removing Document
//-----------------------------------------------------------

// Remove one
db.students.deleteOne({ roll_no: 3 });

// Remove multiple (example: remove inactive)
db.students.deleteMany({ status: "inactive" });

//-----------------------------------------------------------
// 4. Updating Documents
//-----------------------------------------------------------

// (a) Replace entire document
db.students.replaceOne(
    { roll_no: 2 },
    { roll_no: 2, name: "Bobby", age: 21, course: "BCA", marks: [75, 80, 79], status: "active" }
);

// (b) Using modifiers ($set, $inc)
db.students.updateOne(
    { roll_no: 1 },
    { $set: { age: 21 }, $inc: { "marks.0": 2 } }
);

// (c) Upsert (insert if not found)
db.students.updateOne(
    { roll_no: 6 },
    { $set: { name: "Frank", age: 22, course: "BSc", marks: [60, 65, 70], status: "active" } },
    { upsert: true }
);

// (d) Update multiple
db.students.updateMany(
    { course: "BCA" },
    { $set: { department: "Computer Applications" } }
);

// (e) Return updated document (MongoDB 4.2+ syntax)
db.students.findOneAndUpdate(
    { roll_no: 4 },
    { $set: { status: "graduated" } },
    { returnNewDocument: true }
);

//-----------------------------------------------------------
// 5. Execute 10 Queries
//-----------------------------------------------------------

// Q1: Find all documents
db.students.find();

// Q2: Find one specific document
db.students.findOne({ roll_no: 1 });

// Q3: Query with conditional ($gt, $lt)
db.students.find({ age: { $gt: 21 } });

// Q4: OR query
db.students.find({ $or: [{ course: "B.Tech" }, { course: "BCA" }] });

// Q5: $not and conditional semantics
db.students.find({ age: { $not: { $lt: 21 } } });

// Q6: Type-specific (null)
db.students.find({ department: { $exists: false } });

// Q7: Type-specific (regex)
db.students.find({ name: { $regex: /^A/i } });  // names starting with A

// Q8: Querying arrays (marks array contains a value greater than 90)
db.students.find({ marks: { $elemMatch: { $gt: 90 } } });

// Q9: $where query (custom JS condition)
db.students.find({ $where: "this.marks[0] > 80 && this.age < 23" });

// Q10: Cursor methods (limit, skip, sort)
db.students.find().sort({ age: 1 }).skip(1).limit(3);
