import edu.duke.*;

public class PerimeterRunner {
    public double getPerimeter (Shape s) {
        // Start with totalPerim = 0
        double totalPerim = 0.0;
        // Start wth prevPt = the last point 
        Point prevPt = s.getLastPoint();
        // For each point currPt in the shape,
        for (Point currPt : s.getPoints()) {
            // Find distance from prevPt point to currPt 
            double currDist = prevPt.distance(currPt);
            // Update totalPerim by currDist
            totalPerim = totalPerim + currDist;
            // Update prevPt to be currPt
            prevPt = currPt;
        }
        // totalPerim is the answer
        return totalPerim;
    }

    public int getNumPoints (Shape s) {
        
        int count = 0;
        
        for (Point currPt : s.getPoints()) {
            System.out.println("Pt: " + currPt);
            count = count+1;
        }
        return count;
        
    }
    
    public double getAverageLength (Shape s) {
        
        double perimeter = getPerimeter(s);
        int points = getNumPoints(s);
        double average = perimeter/points;
        
        return average;
    }

    public double getLargestSide (Shape s ){
        double largest = 0.0;
        
        Point prevPt = s.getLastPoint();
        // For each point currPt in the shape,
        for (Point currPt : s.getPoints()) {
            // Find distance from prevPt point to currPt             
            double currDist = prevPt.distance(currPt);
            // Update totalPerim by currDist
            if( largest < currDist ){
                largest = currDist;
            }
                      
            prevPt = currPt;
        }
        return largest;
    }
    
    
    public double getLargestX (Shape s ){
        double largest = 0.0;
        
        Point prevPt = s.getLastPoint();
        // For each point currPt in the shape,
        for (Point currPt : s.getPoints()) {
            // Find distance from prevPt point to currPt             
            double currDist = prevPt.distance(currPt);
            // Update totalPerim by currDist
            if( largest < currDist ){
                largest = currDist;
            }
                      
            prevPt = currPt;
        }
    }
    
    public void testPerimeter () {
        FileResource fr = new FileResource();
        Shape s = new Shape(fr);
        
        int NumPoints = getNumPoints(s);
        System.out.println("Points: " + NumPoints);
        
        double length = getPerimeter(s);
        System.out.println("perimeter = " + length);
        
        double average = getAverageLength(s);
        System.out.println("Avg Length: " + average);
        
        double largest = getLargestSide(s);
        System.out.println("Largest Length: " + largest);
        
        double largestX = getLargestX(s);
        System.out.println("Largest X: " + largestX);
    }

    public static void main (String[] args) {
        PerimeterRunner pr = new PerimeterRunner();
        pr.testPerimeter();
    }
}
