## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
**Solution:**
**Reasoning:** 

- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program?
**Solution:**
**Reasoning:** 



- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
1.Finding the max element in an unordered stack would require **O(n)** operations?
2. Finding the min element in an unordered queue would require **O(n)** operations?
3. Finding some element in some Binary Search Tree would require **O(h)** operations?
4. Finding some element in a balanced Binary Search Tree would require **O(log n)** operations?
5. Finding some element in an ordered linked list would require **O(n)** operations (worst case)?
6. Finding some element in an ordered linked list would require **O(n/2)** operations (average case)?
7. Finding some element in an unordered linked list would require **O(n)** operations (worst case)?


8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
**Solution:**
**Reasoning:** 


```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
**Solution:**
**Reasoning:** 


```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
**Solution:**
**Reasoning:** 


At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?
**Solution:** It would take, at most, 10 comparisons. 
**Reasoning:** Dakota and I wrote a replit and actually tried this with a sorted array of 1023 elements, and the result was 10 comparisons.

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
**Solution:** Stack
**Reasoning:**

2. You need to store undo/redo operations in a word processor.
**Solution:** Stack
**Reasoning:**

3. You need to evaluate an expression (i.e., parse).
**Solution:** 
**Reasoning:**

4. You need to store the friendship information on a social networking site. I.e., who is friends with who.
**Solution:** Graph
**Reasoning:**

5. You need to store an image (1000 by 1000 pixels) as a bitmap.
**Solution:** 2D Array
**Reasoning:**

6. To implement printer spooler so that jobs can be printed in the order of their arrival.
**Solution:** Queue
**Reasoning:**

7. To implement back functionality in the internet browser.
**Solution:** Stack
**Reasoning:** So that the last entry is easily retrieved by popping off the top.

8. To store the possible moves in a chess game.
**Solution:** Graph
**Reasoning:** Each move respresents a node, and the graph is fully connected. However, if the player were to lose a piece, then moves that go down that path for that piece could not be travelled on, and therefore the same for all other impossible moves at any given point.

9. To store a set of fixed key words which are referenced very frequently.
**Solution:** Priority Queue
**Reasoning:**

10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
**Solution:** Queue
**Reasoning:**

11. To store the genealogy information of biological species.
**Solution:** Tree
**Reasoning:**

12. To store an alphabetized list of names in order to look up quickly.
**Solution:** 
**Reasoning:**



## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
LASTNAME
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.