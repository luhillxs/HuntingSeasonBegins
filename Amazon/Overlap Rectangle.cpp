/* Overlap Rectangle
==============题目==============
给定两个长方形左下角和右上角的坐标，判断是否有重叠，返回true或者false。
*/

public class OverLap {
  public static class Node 
    {
      double x;
      double y;
      public Node(double x, double y) 
      {
        this.x = x;
        this.y = y; 
      }
    }

	public static boolean check(Node topLeftA, Node topLeftB, Node bottomRightA, Node bottomRightB) 
	{
	    if(bottomRightA.x < topLeftB.x 
	       || topLeftA.x < bottomRightB.x 
         || bottomRightA.y > topLeftB.y 
         || topLeftA.y < bottomRightB.y)
         {
             return false;
         }         
        return true;
	}
}