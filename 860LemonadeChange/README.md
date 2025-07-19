🥤 Leetcode Problem 860 - Lemonade Change
Problem Statement:

You are selling lemonade at $5 per cup. Each customer pays using either a $5, $10, or $20 bill. You must return the correct change to each customer in order.

You start with no change in hand.
Your goal is to determine if it's possible to provide correct change to every customer in the queue.
```
 Example 1:

Input:  bills = [5, 5, 5, 10, 20]  
Output: true
Explanation:

Collect three $5 bills.

Use one $5 to give change for a $10.

Use one $10 and one $5 to give change for a $20.
```
```
 Example 2:

Input:  bills = [5, 5, 10, 10, 20]  
Output: false
Explanation:

After giving change to two $10 customers, you're left with no $5 bills.

You can’t give $15 change for the $20 customer.
```
📌 Constraints:
1 <= bills.length <= 10^5

Each bill is either 5, 10, or 20
