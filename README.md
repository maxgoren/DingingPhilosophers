# Dinging Philosophers
An implementation of the Dining Philosophers Problem re-cast as hungry hungry programmers.

## Dining Philosophers
Edsgar Dijkstra originally proposed the dining philosophers problem as an example of resource management in concurrent
programming. It's an interesting exercise, and he phrased it as thus:


Peter Welch humorously presented a spin on the dining philosophers poblem sometime later in what he titled: 
The Starving Philosophers
       - or -
  W0t? No Chickens!?
in order to point out issues with concurrency with Java.

You can read that here:
https://www.cs.kent.ac.uk/projects/ofa/java-threads/0.html

I've put my own spin on "wot no chickens" to present you with: 

## The Hungry Hungry Programmers Problem
Donald Knuth, Robert Sedgewick, Tony Hoare, Nicholas Wirth, and Edsgar Dijkstra have all congregated on the distinguished campus
of Plattsburgh State University in upstate New York, USA. They have been tasked with writing a program of critical importance require
millions of lines of code that only masters such as themselves could produce. A long debate ensued in which language they would use to
develope this mission critical program in.
-------------------------------------------INTERLUDE------------------------------------------
 Knuth wanted to first build an actual MMIX computer for their project and write the code in MMIX assembly.
Reminding everyone of what happened the last time knuth put a project on hold so he could create a technology
to do the project in, Robert Sedgewick set to the task of trying to get everyone to see how great java has become. 
Wirth, of course, wanted to use pascal, or at least Modula-2. Tony Hoare was just glad he was invited at all and kept profusely 
appologozing to anyone who would listen over the "null reference" thing, especially to Sedgewick, who he knew had a fondness for 
C and C-like languages. Edsgar Dijkstra flat REFUSED to code in anything but ALGOL, and only ALGOL 60 at that. Wirth could get 
behind that! But how about Algol W he said? Dijkstra just glared, and replied through gritted teeth: THERE IS ONLY ONE ALGO: 60.
So it was settled: Dijkstra had spoken, Hoare was anxiously looking around, Wirth was still mumbling about Pascal, and Knuth
and Sedgewick had gotten distracted talking about the amortized running time of a data structure nobody else had even heard of.
---------------------------BACK TO OUR REGULARLY SCHEDULED PROGRAM----------------------------
After a lively discussion, the programmers were all famished, so they decided to retire to Clinton Dining Hall for supper
This is when the real problems began: There was five of them, but the chef could only cook four chickens at a time. 
How could five diners eat together without splitting chickens? They decided that since they were all going to consume more than 
one chicken anyway, they were sure they could all be accomodated even if they had to occasionally wait between servings.
But would they all get fed?

The solution, as Dijkstra determined, was the use of semaphores, in this case we have a waiter that each programmer must ask for a chicken.
If there are chickens available, the waiter serves the programmer a chicken. If their is not enough chicken to fulfill the request,
The waiter informs the kitchen that more chickens are needed, and instructs the diner to please wait, as more chickens are being prepared, after a given
time, the programmer may make its request for chicken again.

In this way, the five programmers are able to dine together, despite the fact that their are only five chickens available at any given time
without splitting a chicken.

I had alot of fun writing this code, and i hope you find it useful, and if not, at least got some kicks reading it.
Cheers! 
-max
