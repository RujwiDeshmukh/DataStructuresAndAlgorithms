# Find k-th missing element
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given two sequences, one is increasing sequence a[] and another a normal sequence b[], find the K-th missing element in the increasing sequence which is not present in the given sequence. If no K-th missing element is there output -1</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input :</strong> Arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 15}
Brr[] = {4, 10, 6, 8, 12}
<strong>Output :</strong> 14
<strong>Explanation:
</strong>The numbers from increasing sequence that
are not present in the given sequence are 0, 2, 14, 15.
The 3rd missing number is 14.

</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input :</strong> Arr[] = {1, 2, 3, 4, 5}
Brr[] = {5, 4, 3, 1, 2} and K = 3
<strong>Output :</strong> -1

</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>MissingNumber()</strong>&nbsp;that takes an&nbsp;array <strong>(a)</strong>, another array <strong>(b)</strong>,&nbsp;an&nbsp;element <strong>K,</strong> size of first array <strong>(n)</strong>, size of the second array <strong>(m)</strong><strong>,&nbsp;</strong>and return the Kth missing number in an array <strong>a,&nbsp;</strong>if you can't find it return <strong>-1</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n + m).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(m).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n,m,k ≤ 10<sup>5</sup><br>
1 ≤ a[i] ≤ 10<sup>8</sup><br>
1 ≤ b[i] ≤ 10<sup>3</sup></span></p>
 <p></p>
            </div>