## Easy LeetCode Solutions

### Problem 455: Assign Cookies

**Link:** [Assign Cookies – Leetcode 455](https://leetcode.com/problems/assign-cookies/)  
**Difficulty:** Easy  
**Tags:** Greedy, Sorting  

---

### 🧒 Problem Description:

Assume you are an awesome parent and want to give your children some cookies.  
Each child `i` has a greed factor `g[i]`, which is the minimum size of a cookie that will make them content.  
Each cookie `j` has a size `s[j]`.  
If `s[j] >= g[i]`, you can assign cookie `j` to child `i`.  
**You can assign at most one cookie per child and per cookie.**

**Your goal:** Maximize the number of content children.

---

### 🔍 Examples:

**Example 1:**
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: Only one child (greed 1) can be satisfied by one cookie (size 1).

markdown
Copy
Edit

**Example 2:**
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: Both children can be satisfied by the available cookies.

yaml
Copy
Edit

---

### 📚 Constraints:
- 1 ≤ g.length ≤ 3 × 10⁴  
- 0 ≤ s.length ≤ 3 × 10⁴  
- 1 ≤ g[i], s[j] ≤ 2³¹ − 1  

---
