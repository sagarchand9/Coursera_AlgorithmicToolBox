import edu.duke.*;
/**
 * Write a description of Debugging_Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Debugging_Part2 {
    
   public void findAbc(String input){
       int index = input.indexOf("abc");

       while (true){
       System.out.println(index);
           if (index == -1 || index >= input.length() - 3){
               break;
           }
           String found = input.substring(index+1, index+4);
           //System.out.println("index " + index);
           index = input.indexOf("abc",index+3);
           //System.out.println("index after updating " + index);
           System.out.println(found);
       }
   }

   public void test(){
       //findAbc("abcd");
       findAbc("abcabcabcabca");
   }

}
