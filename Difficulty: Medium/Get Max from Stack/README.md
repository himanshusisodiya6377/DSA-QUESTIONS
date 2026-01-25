<h2><a href="https://www.geeksforgeeks.org/problems/get-max-from-stack/1">Get Max from Stack</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18.6667px;">Implement a class <strong>SpecialStack</strong> that supports following operations:</span></p>
<ul>
<li style="text-align: left;"><span style="font-size: 18.6667px;"><strong>push(x) –&nbsp;</strong>Insert an integer x onto the stack.</span></li>
<li style="text-align: left;"><span style="font-size: 18.6667px;"><strong>pop() –&nbsp;</strong>Remove the top element from the stack.</span></li>
<li style="text-align: left;"><span style="font-size: 18.6667px;"><strong style="font-size: 18.6667px;">peek() </strong><span style="font-size: 18.6667px;"><strong>–</strong></span><strong style="font-size: 18.6667px;"> </strong><span style="font-size: 18.6667px;">Return the top element&nbsp;</span></span><span style="font-size: 18.6667px;">from the stack.<strong><strong>&nbsp;</strong><span style="font-family: monospace; font-size: 18.6667px; font-weight: 400;">If the stack is empty, return -1.</span></strong></span></li>
<li style="text-align: left;"><span style="font-size: 18.6667px;"><strong>getMax() – </strong>Retrieve the maximum element from the stack in O(1) time. If the stack is empty, return -1.</span></li>
<li style="text-align: left;"><strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: 18.6667px;">isEmpty()</span></strong><span style="font-size: 18.6667px;">&nbsp;</span><span style="font-size: 18.6667px;"><strong>–&nbsp;</strong></span><span style="font-size: 18.6667px;">&nbsp;R</span><span style="font-size: 18.6667px;">eturn true if stack is empty, else false</span></li>
</ul>
<p><span style="font-size: 14pt;"><span style="font-size: 14pt;">There will be a sequence of queries&nbsp;</span><span style="font-size: 18.6667px;"><strong>queries</strong></span><strong style="font-size: 14pt;">[][]</strong><span style="font-size: 14pt;">. The queries are represented in numeric form:</span></span></p>
<ul>
<li><span style="font-size: 14pt;"><strong>1 x</strong>&nbsp;<strong>:</strong> Call push(x)</span></li>
<li><span style="font-size: 14pt;"><span style="font-size: 18.6667px;"><strong>2</strong></span><strong style="font-size: 14pt;">:</strong><span style="font-size: 14pt;">&nbsp;&nbsp;</span><span style="font-size: 14pt;"><span style="font-family: monospace;">Call</span>&nbsp;pop()</span></span></li>
<li><span style="font-family: monospace;"><span style="font-size: 18.6667px;"><strong>3:&nbsp;</strong>Call peek()</span></span></li>
<li><span style="font-family: monospace;"><span style="font-size: 18.6667px;"><strong>4:</strong> Call getMax()</span></span></li>
<li><span style="font-family: monospace;"><span style="font-size: 18.6667px;"><strong>5:</strong> Call isEmpty()</span></span></li>
</ul>
<p><span style="font-family: monospace;"><span style="font-size: 18.6667px;">The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMax(), isEmpty() operations.</span><br></span><span style="font-family: monospace;"><span style="font-size: 18.6667px;">You only need to implement the above five functions.</span></span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]</span><strong style="font-size: 14pt;">
Output: </strong><span style="font-size: 14pt;">[3, 2, 2]</span><strong style="font-size: 14pt;">
Explanation: </strong><span style="font-size: 18.6667px;">Queries on stack are as follows:</span><span style="font-size: 14pt;"><br>push(2) into the Stack
push(3) </span><span style="font-size: 18.6667px;">into the Stack</span><span style="font-size: 14pt;">
return top of the stack, i.e 3
remove the element 3 from the top of the stack
return maximum element from the stack i.e 2
push(1) into the stack
</span><span style="font-size: 18.6667px;">return maximum element from the stack i.e 2</span></span></pre>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input:</strong><span style="font-size: 14pt;"> q = 5, queries[][] = [[1, 4], [1, 2], [4], [3], [5]]</span><strong style="font-size: 14pt;">
Output: </strong><span style="font-size: 14pt;">[4, 2, false]</span><strong style="font-size: 14pt;">
Explanation: </strong><span style="font-size: 14pt;">Queries on stack are as follows:</span><strong style="font-size: 14pt;"><br></strong>push(4) into the Stack
push(2) into the Stack<span style="font-size: 14pt;"><br></span>return maximum element from the stack i.e 4<span style="font-size: 14pt;"><br></span>return top of the stack, i.e 2<br>stack is non-empty, i.e. return false.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:<br></strong></span><span style="font-size: 14pt;">1 ≤ queries.size() ≤ 10<sup>5<br></sup></span><span style="font-size: 14pt;">0 ≤ values on the stack ≤ 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;