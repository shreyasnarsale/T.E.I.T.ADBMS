student@student-ThinkCentre-M700:~$ mongo

------------------------------ PART A ------------------------------

> use dept
switched to db dept

> db.dept.insertMany([
...   { deptno: 10, dname: "ACCOUNTING", loc: "NEW YORK" },
...   { deptno: 20, dname: "RESEARCH", loc: "DALLAS" },
...   { deptno: 30, dname: "SALES", loc: "CHICAGO" },
...   { deptno: 40, dname: "OPERATIONS", loc: "BOSTON" }
... ])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68809c7372027ea615b709fa"),
		ObjectId("68809c7372027ea615b709fb"),
		ObjectId("68809c7372027ea615b709fc"),
		ObjectId("68809c7372027ea615b709fd")
	]
}

> db.emp.insertMany([
...   {
...     empno: 7839, ename: "KING", job: "PRESIDENT", mgr: null,
...     hiredate: new Date("1981-11-17"), sal: 5000, comm: null, deptno: 10
...   },
...   {
...     empno: 7566, ename: "JONES", job: "MANAGER", mgr: 7839,
...     hiredate: new Date("1981-04-02"), sal: 2975, comm: null, deptno: 20
...   },
...   {
...     empno: 7698, ename: "BLAKE", job: "MANAGER", mgr: 7839,
...     hiredate: new Date("1981-05-01"), sal: 2850, comm: null, deptno: 30
...   },
...   {
...     empno: 7782, ename: "CLARK", job: "MANAGER", mgr: 7839,
...     hiredate: new Date("1981-06-09"), sal: 2450, comm: null, deptno: 10
...   },
...   {
...     empno: 7788, ename: "SCOTT", job: "ANALYST", mgr: 7566,
...     hiredate: new Date("1982-12-09"), sal: 3000, comm: null, deptno: 20
...   },
...   {
...     empno: 7902, ename: "FORD", job: "ANALYST", mgr: 7566,
...     hiredate: new Date("1981-12-03"), sal: 3000, comm: null, deptno: 20
...   },
...   {
...     empno: 7844, ename: "TURNER", job: "SALESMAN", mgr: 7698,
...     hiredate: new Date("1981-09-08"), sal: 1500, comm: 0, deptno: 30
...   },
...   {
...     empno: 7900, ename: "JAMES", job: "CLERK", mgr: 7698,
...     hiredate: new Date("1981-12-03"), sal: 950, comm: null, deptno: 30
...   },
...   {
...     empno: 7654, ename: "MARTIN", job: "SALESMAN", mgr: 7698,
...     hiredate: new Date("1981-09-28"), sal: 1250, comm: 1400, deptno: 30
...   },
...   {
...     empno: 7499, ename: "ALLEN", job: "SALESMAN", mgr: 7698,
...     hiredate: new Date("1981-02-20"), sal: 1600, comm: 300, deptno: 30
...   },
...   {
...     empno: 7521, ename: "WARD", job: "SALESMAN", mgr: 7698,
...     hiredate: new Date("1981-02-22"), sal: 1250, comm: 500, deptno: 30
...   },
...   {
...     empno: 7934, ename: "MILLER", job: "CLERK", mgr: 7782,
...     hiredate: new Date("1982-01-23"), sal: 1300, comm: null, deptno: 10
...   },
...   {
...     empno: 7876, ename: "ADAMS", job: "CLERK", mgr: 7788,
...     hiredate: new Date("1983-01-12"), sal: 1100, comm: null, deptno: 20
...   },
...   {
...     empno: 7369, ename: "SMITH", job: "CLERK", mgr: 7902,
...     hiredate: new Date("1980-12-17"), sal: 800, comm: null, deptno: 20
...   }
... ]);
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("68809d3072027ea615b709fe"),
		ObjectId("68809d3072027ea615b709ff"),
		ObjectId("68809d3072027ea615b70a00"),
		ObjectId("68809d3072027ea615b70a01"),
		ObjectId("68809d3072027ea615b70a02"),
		ObjectId("68809d3072027ea615b70a03"),
		ObjectId("68809d3072027ea615b70a04"),
		ObjectId("68809d3072027ea615b70a05"),
		ObjectId("68809d3072027ea615b70a06"),
		ObjectId("68809d3072027ea615b70a07"),
		ObjectId("68809d3072027ea615b70a08"),
		ObjectId("68809d3072027ea615b70a09"),
		ObjectId("68809d3072027ea615b70a0a"),
		ObjectId("68809d3072027ea615b70a0b")
	]
}

> db.emp.find().pretty()
{
	"_id" : ObjectId("68809d3072027ea615b709fe"),
	"empno" : 7839,
	"ename" : "KING",
	"job" : "PRESIDENT",
	"mgr" : null,
	"hiredate" : ISODate("1981-11-17T00:00:00Z"),
	"sal" : 5000,
	"comm" : null,
	"deptno" : 10
}
{
	"_id" : ObjectId("68809d3072027ea615b709ff"),
	"empno" : 7566,
	"ename" : "JONES",
	"job" : "MANAGER",
	"mgr" : 7839,
	"hiredate" : ISODate("1981-04-02T00:00:00Z"),
	"sal" : 2975,
	"comm" : null,
	"deptno" : 20
}
{
	"_id" : ObjectId("68809d3072027ea615b70a00"),
	"empno" : 7698,
	"ename" : "BLAKE",
	"job" : "MANAGER",
	"mgr" : 7839,
	"hiredate" : ISODate("1981-05-01T00:00:00Z"),
	"sal" : 2850,
	"comm" : null,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a01"),
	"empno" : 7782,
	"ename" : "CLARK",
	"job" : "MANAGER",
	"mgr" : 7839,
	"hiredate" : ISODate("1981-06-09T00:00:00Z"),
	"sal" : 2450,
	"comm" : null,
	"deptno" : 10
}
{
	"_id" : ObjectId("68809d3072027ea615b70a02"),
	"empno" : 7788,
	"ename" : "SCOTT",
	"job" : "ANALYST",
	"mgr" : 7566,
	"hiredate" : ISODate("1982-12-09T00:00:00Z"),
	"sal" : 3000,
	"comm" : null,
	"deptno" : 20
}
{
	"_id" : ObjectId("68809d3072027ea615b70a03"),
	"empno" : 7902,
	"ename" : "FORD",
	"job" : "ANALYST",
	"mgr" : 7566,
	"hiredate" : ISODate("1981-12-03T00:00:00Z"),
	"sal" : 3000,
	"comm" : null,
	"deptno" : 20
}
{
	"_id" : ObjectId("68809d3072027ea615b70a04"),
	"empno" : 7844,
	"ename" : "TURNER",
	"job" : "SALESMAN",
	"mgr" : 7698,
	"hiredate" : ISODate("1981-09-08T00:00:00Z"),
	"sal" : 1500,
	"comm" : 0,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a05"),
	"empno" : 7900,
	"ename" : "JAMES",
	"job" : "CLERK",
	"mgr" : 7698,
	"hiredate" : ISODate("1981-12-03T00:00:00Z"),
	"sal" : 950,
	"comm" : null,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a06"),
	"empno" : 7654,
	"ename" : "MARTIN",
	"job" : "SALESMAN",
	"mgr" : 7698,
	"hiredate" : ISODate("1981-09-28T00:00:00Z"),
	"sal" : 1250,
	"comm" : 1400,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a07"),
	"empno" : 7499,
	"ename" : "ALLEN",
	"job" : "SALESMAN",
	"mgr" : 7698,
	"hiredate" : ISODate("1981-02-20T00:00:00Z"),
	"sal" : 1600,
	"comm" : 300,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a08"),
	"empno" : 7521,
	"ename" : "WARD",
	"job" : "SALESMAN",
	"mgr" : 7698,
	"hiredate" : ISODate("1981-02-22T00:00:00Z"),
	"sal" : 1250,
	"comm" : 500,
	"deptno" : 30
}
{
	"_id" : ObjectId("68809d3072027ea615b70a09"),
	"empno" : 7934,
	"ename" : "MILLER",
	"job" : "CLERK",
	"mgr" : 7782,
	"hiredate" : ISODate("1982-01-23T00:00:00Z"),
	"sal" : 1300,
	"comm" : null,
	"deptno" : 10
}
{
	"_id" : ObjectId("68809d3072027ea615b70a0a"),
	"empno" : 7876,
	"ename" : "ADAMS",
	"job" : "CLERK",
	"mgr" : 7788,
	"hiredate" : ISODate("1983-01-12T00:00:00Z"),
	"sal" : 1100,
	"comm" : null,
	"deptno" : 20
}
{
	"_id" : ObjectId("68809d3072027ea615b70a0b"),
	"empno" : 7369,
	"ename" : "SMITH",
	"job" : "CLERK",
	"mgr" : 7902,
	"hiredate" : ISODate("1980-12-17T00:00:00Z"),
	"sal" : 800,
	"comm" : null,
	"deptno" : 20
}

> db.dept.find().pretty()
{
	"_id" : ObjectId("68809c7372027ea615b709fa"),
	"deptno" : 10,
	"dname" : "ACCOUNTING",
	"loc" : "NEW YORK"
}
{
	"_id" : ObjectId("68809c7372027ea615b709fb"),
	"deptno" : 20,
	"dname" : "RESEARCH",
	"loc" : "DALLAS"
}
{
	"_id" : ObjectId("68809c7372027ea615b709fc"),
	"deptno" : 30,
	"dname" : "SALES",
	"loc" : "CHICAGO"
}
{
	"_id" : ObjectId("68809c7372027ea615b709fd"),
	"deptno" : 40,
	"dname" : "OPERATIONS",
	"loc" : "BOSTON"
}

> db.emp.find({ job: { $in: ["ANALYST", "SALESMAN"] } }, { ename: 1, _id: 0 });
{ "ename" : "SCOTT" }
{ "ename" : "FORD" }
{ "ename" : "TURNER" }
{ "ename" : "MARTIN" }
{ "ename" : "ALLEN" }
{ "ename" : "WARD" }

> db.emp.find({ hiredate: { $lt: new Date("1981-09-30") } });
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "empno" : 7566, "ename" : "JONES", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-04-02T00:00:00Z"), "sal" : 2975, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "empno" : 7698, "ename" : "BLAKE", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-05-01T00:00:00Z"), "sal" : 2850, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "empno" : 7782, "ename" : "CLARK", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-06-09T00:00:00Z"), "sal" : 2450, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "empno" : 7654, "ename" : "MARTIN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-28T00:00:00Z"), "sal" : 1250, "comm" : 1400, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "empno" : 7499, "ename" : "ALLEN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-20T00:00:00Z"), "sal" : 1600, "comm" : 300, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "empno" : 7521, "ename" : "WARD", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-22T00:00:00Z"), "sal" : 1250, "comm" : 500, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }

> db.emp.find({ job: { $ne: "MANAGER" } }, { ename: 1 });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING" }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "ename" : "SCOTT" }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "ename" : "FORD" }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "ename" : "TURNER" }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "ename" : "JAMES" }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "ename" : "MARTIN" }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "ename" : "ALLEN" }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "ename" : "WARD" }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER" }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "ename" : "ADAMS" }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "ename" : "SMITH" }

> db.emp.find({ empno: { $in: [7369, 7521, 7839, 7934, 7788] } });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "empno" : 7839, "ename" : "KING", "job" : "PRESIDENT", "mgr" : null, "hiredate" : ISODate("1981-11-17T00:00:00Z"), "sal" : 5000, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "empno" : 7788, "ename" : "SCOTT", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1982-12-09T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "empno" : 7521, "ename" : "WARD", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-22T00:00:00Z"), "sal" : 1250, "comm" : 500, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "empno" : 7934, "ename" : "MILLER", "job" : "CLERK", "mgr" : 7782, "hiredate" : ISODate("1982-01-23T00:00:00Z"), "sal" : 1300, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }

> db.emp.find({ deptno: { $nin: [10, 30, 40] } });
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "empno" : 7566, "ename" : "JONES", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-04-02T00:00:00Z"), "sal" : 2975, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "empno" : 7788, "ename" : "SCOTT", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1982-12-09T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "empno" : 7902, "ename" : "FORD", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "empno" : 7876, "ename" : "ADAMS", "job" : "CLERK", "mgr" : 7788, "hiredate" : ISODate("1983-01-12T00:00:00Z"), "sal" : 1100, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }

> db.emp.find({
...   hiredate: {
...     $gte: new Date("1981-06-30"),
...     $lte: new Date("1981-12-31")
...   }
... });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "empno" : 7839, "ename" : "KING", "job" : "PRESIDENT", "mgr" : null, "hiredate" : ISODate("1981-11-17T00:00:00Z"), "sal" : 5000, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "empno" : 7902, "ename" : "FORD", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "empno" : 7900, "ename" : "JAMES", "job" : "CLERK", "mgr" : 7698, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 950, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "empno" : 7654, "ename" : "MARTIN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-28T00:00:00Z"), "sal" : 1250, "comm" : 1400, "deptno" : 30 }

> db.emp.distinct("job");
[ "PRESIDENT", "MANAGER", "ANALYST", "SALESMAN", "CLERK" ]

> db.emp.find({ comm: { $in: [null, 0] } });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "empno" : 7839, "ename" : "KING", "job" : "PRESIDENT", "mgr" : null, "hiredate" : ISODate("1981-11-17T00:00:00Z"), "sal" : 5000, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "empno" : 7566, "ename" : "JONES", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-04-02T00:00:00Z"), "sal" : 2975, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "empno" : 7698, "ename" : "BLAKE", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-05-01T00:00:00Z"), "sal" : 2850, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "empno" : 7782, "ename" : "CLARK", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-06-09T00:00:00Z"), "sal" : 2450, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "empno" : 7788, "ename" : "SCOTT", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1982-12-09T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "empno" : 7902, "ename" : "FORD", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "empno" : 7900, "ename" : "JAMES", "job" : "CLERK", "mgr" : 7698, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 950, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "empno" : 7934, "ename" : "MILLER", "job" : "CLERK", "mgr" : 7782, "hiredate" : ISODate("1982-01-23T00:00:00Z"), "sal" : 1300, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "empno" : 7876, "ename" : "ADAMS", "job" : "CLERK", "mgr" : 7788, "hiredate" : ISODate("1983-01-12T00:00:00Z"), "sal" : 1100, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }

> db.emp.find({ mgr: null }, { ename: 1, job: 1 });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING", "job" : "PRESIDENT" }

> db.emp.find({ deptno: null });

> db.emp.find({ comm: { $ne: null } });
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "empno" : 7654, "ename" : "MARTIN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-28T00:00:00Z"), "sal" : 1250, "comm" : 1400, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "empno" : 7499, "ename" : "ALLEN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-20T00:00:00Z"), "sal" : 1600, "comm" : 300, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "empno" : 7521, "ename" : "WARD", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-22T00:00:00Z"), "sal" : 1250, "comm" : 500, "deptno" : 30 }

> db.emp.find({ ename: { $regex: /^S|S$/i } }, { ename: 1 });
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "ename" : "JONES" }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "ename" : "SCOTT" }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "ename" : "JAMES" }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "ename" : "ADAMS" }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "ename" : "SMITH" }

> db.emp.find({ ename: { $regex: /^.i/i } }, { ename: 1 });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING" }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER" }

> db.emp.find({ ename: { $regex: /^.i/i } }, { ename: 1 });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING" }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER" }

> db.dept.find().count();
4

> db.emp.find().count();
14

> db.emp.distinct("job").length;
5

> db.emp.aggregate([
...   { $group: { _id: null, totalSalary: { $sum: "$sal" } } }
... ]);
{ "_id" : null, "totalSalary" : 29025 }

> db.emp.aggregate([
...   {
...     $group: {
...       _id: null,
...       maxSal: { $max: "$sal" },
...       minSal: { $min: "$sal" },
...       avgSal: { $avg: "$sal" }
...     }
...   }
... ]);
{ "_id" : null, "maxSal" : 5000, "minSal" : 800, "avgSal" : 2073.214285714286 }

> db.emp.aggregate([
...   { $match: { job: "SALESMAN" } },
...   { $group: { _id: null, maxSal: { $max: "$sal" } } }
... ]);
{ "_id" : null, "maxSal" : 1600 }


------------------------------ PART B -----------------------------

> db.emp.aggregate([
...   { $match: { deptno: 20 } },
...   {
...     $group: {
...       _id: null,
...       empCount: { $sum: 1 },
...       avgSalary: { $avg: "$sal" }
...     }
...   }
... ]);
{ "_id" : null, "empCount" : 5, "avgSalary" : 2175 }

> db.emp.aggregate([
...   {
...     $project: {
...       ename: 1,
...       sal: 1,
...       pf: { $multiply: ["$sal", 0.1] }
...     }
...   }
... ]);
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING", "sal" : 5000, "pf" : 500 }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "ename" : "JONES", "sal" : 2975, "pf" : 297.5 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "ename" : "BLAKE", "sal" : 2850, "pf" : 285 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "ename" : "CLARK", "sal" : 2450, "pf" : 245 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "ename" : "SCOTT", "sal" : 3000, "pf" : 300 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "ename" : "FORD", "sal" : 3000, "pf" : 300 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "ename" : "TURNER", "sal" : 1500, "pf" : 150 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "ename" : "JAMES", "sal" : 950, "pf" : 95 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "ename" : "MARTIN", "sal" : 1250, "pf" : 125 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "ename" : "ALLEN", "sal" : 1600, "pf" : 160 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "ename" : "WARD", "sal" : 1250, "pf" : 125 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER", "sal" : 1300, "pf" : 130 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "ename" : "ADAMS", "sal" : 1100, "pf" : 110 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "ename" : "SMITH", "sal" : 800, "pf" : 80 }

> db.emp.find({
...   hiredate: {
...     $lt: new Date(new Date().setFullYear(new Date().getFullYear() - 2))
...   }
... });
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "empno" : 7839, "ename" : "KING", "job" : "PRESIDENT", "mgr" : null, "hiredate" : ISODate("1981-11-17T00:00:00Z"), "sal" : 5000, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "empno" : 7566, "ename" : "JONES", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-04-02T00:00:00Z"), "sal" : 2975, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "empno" : 7698, "ename" : "BLAKE", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-05-01T00:00:00Z"), "sal" : 2850, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "empno" : 7782, "ename" : "CLARK", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-06-09T00:00:00Z"), "sal" : 2450, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "empno" : 7788, "ename" : "SCOTT", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1982-12-09T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "empno" : 7902, "ename" : "FORD", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "empno" : 7900, "ename" : "JAMES", "job" : "CLERK", "mgr" : 7698, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 950, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "empno" : 7654, "ename" : "MARTIN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-28T00:00:00Z"), "sal" : 1250, "comm" : 1400, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "empno" : 7499, "ename" : "ALLEN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-20T00:00:00Z"), "sal" : 1600, "comm" : 300, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "empno" : 7521, "ename" : "WARD", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-22T00:00:00Z"), "sal" : 1250, "comm" : 500, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "empno" : 7934, "ename" : "MILLER", "job" : "CLERK", "mgr" : 7782, "hiredate" : ISODate("1982-01-23T00:00:00Z"), "sal" : 1300, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "empno" : 7876, "ename" : "ADAMS", "job" : "CLERK", "mgr" : 7788, "hiredate" : ISODate("1983-01-12T00:00:00Z"), "sal" : 1100, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }

> db.emp.find().sort({ sal: 1 });
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "empno" : 7369, "ename" : "SMITH", "job" : "CLERK", "mgr" : 7902, "hiredate" : ISODate("1980-12-17T00:00:00Z"), "sal" : 800, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "empno" : 7900, "ename" : "JAMES", "job" : "CLERK", "mgr" : 7698, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 950, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "empno" : 7876, "ename" : "ADAMS", "job" : "CLERK", "mgr" : 7788, "hiredate" : ISODate("1983-01-12T00:00:00Z"), "sal" : 1100, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "empno" : 7654, "ename" : "MARTIN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-28T00:00:00Z"), "sal" : 1250, "comm" : 1400, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "empno" : 7521, "ename" : "WARD", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-22T00:00:00Z"), "sal" : 1250, "comm" : 500, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "empno" : 7934, "ename" : "MILLER", "job" : "CLERK", "mgr" : 7782, "hiredate" : ISODate("1982-01-23T00:00:00Z"), "sal" : 1300, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "empno" : 7844, "ename" : "TURNER", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-09-08T00:00:00Z"), "sal" : 1500, "comm" : 0, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "empno" : 7499, "ename" : "ALLEN", "job" : "SALESMAN", "mgr" : 7698, "hiredate" : ISODate("1981-02-20T00:00:00Z"), "sal" : 1600, "comm" : 300, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "empno" : 7782, "ename" : "CLARK", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-06-09T00:00:00Z"), "sal" : 2450, "comm" : null, "deptno" : 10 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "empno" : 7698, "ename" : "BLAKE", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-05-01T00:00:00Z"), "sal" : 2850, "comm" : null, "deptno" : 30 }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "empno" : 7566, "ename" : "JONES", "job" : "MANAGER", "mgr" : 7839, "hiredate" : ISODate("1981-04-02T00:00:00Z"), "sal" : 2975, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "empno" : 7788, "ename" : "SCOTT", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1982-12-09T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "empno" : 7902, "ename" : "FORD", "job" : "ANALYST", "mgr" : 7566, "hiredate" : ISODate("1981-12-03T00:00:00Z"), "sal" : 3000, "comm" : null, "deptno" : 20 }
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "empno" : 7839, "ename" : "KING", "job" : "PRESIDENT", "mgr" : null, "hiredate" : ISODate("1981-11-17T00:00:00Z"), "sal" : 5000, "comm" : null, "deptno" : 10 }

> db.emp.find({}, { ename: 1, hiredate: 1 }).sort({ hiredate: -1 });
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "ename" : "ADAMS", "hiredate" : ISODate("1983-01-12T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "ename" : "SCOTT", "hiredate" : ISODate("1982-12-09T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER", "hiredate" : ISODate("1982-01-23T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "ename" : "FORD", "hiredate" : ISODate("1981-12-03T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "ename" : "JAMES", "hiredate" : ISODate("1981-12-03T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING", "hiredate" : ISODate("1981-11-17T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "ename" : "MARTIN", "hiredate" : ISODate("1981-09-28T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "ename" : "TURNER", "hiredate" : ISODate("1981-09-08T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "ename" : "CLARK", "hiredate" : ISODate("1981-06-09T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "ename" : "BLAKE", "hiredate" : ISODate("1981-05-01T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "ename" : "JONES", "hiredate" : ISODate("1981-04-02T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "ename" : "WARD", "hiredate" : ISODate("1981-02-22T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "ename" : "ALLEN", "hiredate" : ISODate("1981-02-20T00:00:00Z") }
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "ename" : "SMITH", "hiredate" : ISODate("1980-12-17T00:00:00Z") }

> db.emp.aggregate([
...   {
...     $project: {
...       ename: 1,
...       sal: 1,
...       pf: { $multiply: ["$sal", 0.1] },
...       hra: { $multiply: ["$sal", 0.5] },
...       da: { $multiply: ["$sal", 0.3] },
...       gross: {
...         $add: [
...           "$sal",
...           { $multiply: ["$sal", 0.5] },
...           { $multiply: ["$sal", 0.3] }
...         ]
...       }
...     }
...   },
...   { $sort: { gross: 1 } }
... ]);
{ "_id" : ObjectId("68809d3072027ea615b70a0b"), "ename" : "SMITH", "sal" : 800, "pf" : 80, "hra" : 400, "da" : 240, "gross" : 1440 }
{ "_id" : ObjectId("68809d3072027ea615b70a05"), "ename" : "JAMES", "sal" : 950, "pf" : 95, "hra" : 475, "da" : 285, "gross" : 1710 }
{ "_id" : ObjectId("68809d3072027ea615b70a0a"), "ename" : "ADAMS", "sal" : 1100, "pf" : 110, "hra" : 550, "da" : 330, "gross" : 1980 }
{ "_id" : ObjectId("68809d3072027ea615b70a06"), "ename" : "MARTIN", "sal" : 1250, "pf" : 125, "hra" : 625, "da" : 375, "gross" : 2250 }
{ "_id" : ObjectId("68809d3072027ea615b70a08"), "ename" : "WARD", "sal" : 1250, "pf" : 125, "hra" : 625, "da" : 375, "gross" : 2250 }
{ "_id" : ObjectId("68809d3072027ea615b70a09"), "ename" : "MILLER", "sal" : 1300, "pf" : 130, "hra" : 650, "da" : 390, "gross" : 2340 }
{ "_id" : ObjectId("68809d3072027ea615b70a04"), "ename" : "TURNER", "sal" : 1500, "pf" : 150, "hra" : 750, "da" : 450, "gross" : 2700 }
{ "_id" : ObjectId("68809d3072027ea615b70a07"), "ename" : "ALLEN", "sal" : 1600, "pf" : 160, "hra" : 800, "da" : 480, "gross" : 2880 }
{ "_id" : ObjectId("68809d3072027ea615b70a01"), "ename" : "CLARK", "sal" : 2450, "pf" : 245, "hra" : 1225, "da" : 735, "gross" : 4410 }
{ "_id" : ObjectId("68809d3072027ea615b70a00"), "ename" : "BLAKE", "sal" : 2850, "pf" : 285, "hra" : 1425, "da" : 855, "gross" : 5130 }
{ "_id" : ObjectId("68809d3072027ea615b709ff"), "ename" : "JONES", "sal" : 2975, "pf" : 297.5, "hra" : 1487.5, "da" : 892.5, "gross" : 5355 }
{ "_id" : ObjectId("68809d3072027ea615b70a02"), "ename" : "SCOTT", "sal" : 3000, "pf" : 300, "hra" : 1500, "da" : 900, "gross" : 5400 }
{ "_id" : ObjectId("68809d3072027ea615b70a03"), "ename" : "FORD", "sal" : 3000, "pf" : 300, "hra" : 1500, "da" : 900, "gross" : 5400 }
{ "_id" : ObjectId("68809d3072027ea615b709fe"), "ename" : "KING", "sal" : 5000, "pf" : 500, "hra" : 2500, "da" : 1500, "gross" : 9000 }

> db.emp.aggregate([
...   { $group: { _id: "$deptno", empCount: { $sum: 1 } } }
... ]);
{ "_id" : 30, "empCount" : 6 }
{ "_id" : 20, "empCount" : 5 }
{ "_id" : 10, "empCount" : 3 }

> db.emp.aggregate([
...   { $group: { _id: "$deptno", totalSal: { $sum: "$sal" } } }
... ]);
{ "_id" : 30, "totalSal" : 9400 }
{ "_id" : 20, "totalSal" : 10875 }
{ "_id" : 10, "totalSal" : 8750 }

> db.emp.aggregate([
...   { $group: { _id: "$job", empCount: { $sum: 1 } } },
...   { $sort: { empCount: -1 } }
... ]);
{ "_id" : "CLERK", "empCount" : 4 }
{ "_id" : "SALESMAN", "empCount" : 4 }
{ "_id" : "MANAGER", "empCount" : 3 }
{ "_id" : "ANALYST", "empCount" : 2 }
{ "_id" : "PRESIDENT", "empCount" : 1 }

> db.emp.aggregate([
...   {
...     $group: {
...       _id: "$job",
...       totalSal: { $sum: "$sal" },
...       maxSal: { $max: "$sal" },
...       minSal: { $min: "$sal" },
...       avgSal: { $avg: "$sal" }
...     }
...   }
... ]);
{ "_id" : "CLERK", "totalSal" : 4150, "maxSal" : 1300, "minSal" : 800, "avgSal" : 1037.5 }
{ "_id" : "SALESMAN", "totalSal" : 5600, "maxSal" : 1600, "minSal" : 1250, "avgSal" : 1400 }
{ "_id" : "ANALYST", "totalSal" : 6000, "maxSal" : 3000, "minSal" : 3000, "avgSal" : 3000 }
{ "_id" : "MANAGER", "totalSal" : 8275, "maxSal" : 2975, "minSal" : 2450, "avgSal" : 2758.3333333333335 }
{ "_id" : "PRESIDENT", "totalSal" : 5000, "maxSal" : 5000, "minSal" : 5000, "avgSal" : 5000 }

> db.emp.aggregate([
...   { $match: { deptno: 20 } },
...   {
...     $group: {
...       _id: null,
...       totalSal: { $sum: "$sal" },
...       maxSal: { $max: "$sal" },
...       minSal: { $min: "$sal" },
...       avgSal: { $avg: "$sal" }
...     }
...   }
... ]);
{ "_id" : null, "totalSal" : 10875, "maxSal" : 3000, "minSal" : 800, "avgSal" : 2175 }

> db.emp.aggregate([
...   { $match: { deptno: 20 } },
...   {
...     $group: {
...       _id: "$job",
...       totalSal: { $sum: "$sal" },
...       maxSal: { $max: "$sal" },
...       minSal: { $min: "$sal" },
...       avgSal: { $avg: "$sal" }
...     }
...   },
...   { $match: { avgSal: { $gt: 1000 } } }
... ]);
{ "_id" : "ANALYST", "totalSal" : 6000, "maxSal" : 3000, "minSal" : 3000, "avgSal" : 3000 }
{ "_id" : "MANAGER", "totalSal" : 2975, "maxSal" : 2975, "minSal" : 2975, "avgSal" : 2975 }





