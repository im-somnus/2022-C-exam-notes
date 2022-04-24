# 2021 MIDTERM SOLUTION

This is the 2021 midterm exam for concurrency programming subject. <br>
In this solution, I decided not to follow the instructions for the [output](./Exam%202021%20C/driver_output.txt) and just make my own, which in my opinion, is more readable this way.

<pre>
Initializing and showing the framework:

[Framework]
	[Node 0][5]->()->()->()->()->()
	[Node 1][5]->()->()->()->()->()
	[Node 2][5]->()->()->()->()->()
	[Node 3][5]->()->()->()->()->()
	[Node 4][5]->()->()->()->()->()
[/Framework]

Inserted v1 - CPU=3
Inserted v2 - CPU=5
Inserted v3 - CPU=1
Inserted v4 - CPU=2
Not inserted v5 - CPU=6
Inserted v6 - CPU=4
Showing after insertions:

[Framework]
	[Node 0][1]->(v3|1)->(v1|3)
	[Node 1][0]->(v2|5)
	[Node 2][3]->(v4|2)
	[Node 3][1]->(v6|4)
	[Node 4][5]->()->()->()->()->()
[/Framework]

Freeing the VNF v1 and showing

[Framework]
	[Node 0][4]->(v3|1)
	[Node 1][0]->(v2|5)
	[Node 2][3]->(v4|2)
	[Node 3][1]->(v6|4)
	[Node 4][5]->()->()->()->()->()
[/Framework]

VNFs stored into deployedVNFs.dat
Destroying the framework and showing
Framework is empty.
</pre>
