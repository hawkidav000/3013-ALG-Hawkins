## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.<br>
**Solution:** O(1), O(log n), O(n), O(n log n), O(n<sup>2</sup>), O(n!)<br>

- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program?<br>
**Solution:** 40 seconds<br>
**Reasoning:** First, plug in the factor that the data size was increased by (2) into the complexity (n<sup>2</sup>). You multiply the time (10 seconds) by that result (4) to get the answer.<br>



- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
1. Finding the max element in an unordered stack would require **O(n)** operations.
2. Finding the min element in an unordered queue would require **O(n)** operations.
3. Finding some element in some Binary Search Tree would require **O(h)** operations.
4. Finding some element in a balanced Binary Search Tree would require **O(log n)** operations.
5. Finding some element in an ordered linked list would require **O(n)** operations (worst case).
6. Finding some element in an ordered linked list would require **O(n/2)** operations (average case).
7. Finding some element in an unordered linked list would require **O(n)** operations (worst case).


8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
**Solution:** n<sup>2</sup> operations.<br>
**Reasoning:** The outer loop will run n times, and for every time the outer loop runs once the inner loop runs n times. This produces n X n operations, which is n<sup>2</sup> operations.<br>


```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
**Solution:** n<sup>2</sup> operations.<br>
**Reasoning:** The outer loop will run n/2 times, and every time the outer loop runs once the inner loop will run n times. The solution is n<sup>2</sup> because this produces n<sup>2</sup>/2, and when considering complexities, all constants are disregarded, so the solution is n<sup>2</sup>.<br>


```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
**Solution:** n log(n) operations.<br>
**Reasoning:** The outer loop will run log(n) times, and every time the outer loop runs once the inner loop will run n times. This produces n log(n) operations total.<br>


9. At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?<br>
**Solution:** It would take, at most, 10 comparisons. <br>
**Reasoning:** Dakota and I wrote a replit and actually tried this with a sorted array of 1023 elements, and the result was 10 comparisons.<br>

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.<br>
**Solution:** List-based Priority Queue<br>
**Reasoning:** I chose this implementation because I wanted to make priority be the level of activity on a post (node). I would do it where likes and reactions incremented priority by 1 and comments on posts would increment priority by 2.<br>

2. You need to store undo/redo operations in a word processor.<br>
**Solution:** Stack<br>
**Reasoning:** To access the most recent version of the document, just pop one edit off the top of the stack.<br>

3. You need to evaluate an expression (i.e., parse).<br>
**Solution:** Doubly Linked List<br>
**Reasoning:** I would have a search algorithm that found where the furthest open parenthesis is, and then using pointers to locate the close parenthesis, I would work my way from the inside moving outward and editing the list as it goes.<br>

4. You need to store the friendship information on a social networking site. I.e., who is friends with who.<br>
**Solution:** Graph<br>
**Reasoning:** Nodes are people, and edges are relationships.<br>

5. You need to store an image (1000 by 1000 pixels) as a bitmap.<br>
**Solution:** 2D Array<br>
**Reasoning:** Quick and efficient.<br>

6. To implement printer spooler so that jobs can be printed in the order of their arrival.<br>
**Solution:** Queue<br>
**Reasoning:** Processes jobs in the order of their arrival (FIFO).<br>

7. To implement back functionality in the internet browser.<br>
**Solution:** Stack<br>
**Reasoning:** So that the last entry is easily retrieved by popping off the top.<br>

8. To store the possible moves in a chess game.<br>
**Solution:** Graph<br>
**Reasoning:** Each move respresents a node, and the graph is fully connected. However, if the player were to lose a piece, then moves that go down that path for that piece could not be travelled on, and therefore the same for all other impossible moves at any given point.<br>

9. To store a set of fixed key words which are referenced very frequently.<br>
**Solution:** Priority Queue<br>
**Reasoning:** Whenever a word is accessed, increment its priority and reorder the queue.<br>

10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)<br>
**Solution:** Queue<br>
**Reasoning:** FIFO.<br>

11. To store the genealogy information of biological species.<br>
**Solution:** Tree<br>
**Reasoning:** Trees are good for showing descendants and parent species.<br>

12. To store an alphabetized list of names in order to look up quickly.<br>
**Solution:** Array<br>
**Reasoning:** I would use a binary search to find names.<br>



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
