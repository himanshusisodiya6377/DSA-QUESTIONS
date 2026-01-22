<h2><a href="https://www.geeksforgeeks.org/problems/k-sorted-array1610/1">k sorted array</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of&nbsp;<strong>n</strong>&nbsp;distinct elements. Check whether the given array is a <strong>k-sorted</strong>&nbsp;array or not. A <strong>k-sorted</strong>&nbsp;array is an array where each element is at most&nbsp;<strong>k</strong> distance away from its target position in the sorted array.&nbsp;<br>Return "<strong>Yes</strong>" if the array is a k-sorted array else return "<strong>No</strong>".</span></p>
<p><span style="font-size: 18px;"><strong>Examples</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n=6, arr[] = {3, 2, 1, 5, 6, 4}, k = 2
<strong>Output:</strong> Yes
<strong>Explanation</strong>: Every element is at most <strong>2</strong> distance away from its target position in thesorted array.  </span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n=7, arr[] = {13, 8, 10, 7, 15, 14, 12}, k = 1
<strong>Output:</strong> No</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(nlogn).<br><strong>Expected Auxiliary Space:</strong> O(n).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup><br>0 ≤ k ≤ n</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Binary Search</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;