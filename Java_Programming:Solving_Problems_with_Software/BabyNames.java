import edu.duke.*;
import java.io.File;
import org.apache.commons.csv.*;
/**
 * Write a description of finalOne here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class finalOne {
    
    public void totalBirths(FileResource fr){
        int totalBirths = 0;
        int totalBoys = 0;
        int totalGirls = 0;
        int numB = 0;
        int numG = 0;
        int numT = 0;
        for(CSVRecord rec : fr.getCSVParser(false)){
            int newBorn = Integer.parseInt(rec.get(2));
            totalBirths += newBorn;
            numT += 1;
            if(rec.get(1).equals("M")){
                totalBoys += newBorn;
                numB += 1;
            }
            else{
                totalGirls += newBorn;
                numG += 1;                
            }
        }
        
        System.out.println("TOTAL Names : " + numT);
        System.out.println("BOYS  Names : " + numB);
        System.out.println("GIRLS Names : " + numG);
        
        System.out.println("TOTAL : " + totalBirths);
        System.out.println("BOYS  : " + totalBoys);
        System.out.println("GIRLS : " + totalGirls);        
    }
    
    public int getRank(int year, String name, String gender){

        //FileResource fr = new FileResource();
        String yr = String.valueOf(year);
        //FileResource fr = new FileResource(yr + ".csv");
        FileResource fr = new FileResource("us_babynames_by_year/yob"+yr+".csv");
        int rank = 0;
        
        for(CSVRecord rec : fr.getCSVParser(false)){
            String genderF = rec.get(1);
            String nameF = rec.get(0);
            if(genderF.equals(gender)){
                rank += 1;
                if(nameF.equals(name)){
                    break;
                }                
            }
        }
        if(rank == 0){
            return -1;
        }
        return rank;
    }
    
    public String getName(int year, int rank, String gender){
        //FileResource fr = new FileResource("us_babynames_by_year/yob"+(String)year+".csv");
        FileResource fr = new FileResource();
        int rankF = 0;
        
        for(CSVRecord rec : fr.getCSVParser(false)){
            String genderF = rec.get(1);
            String nameF = rec.get(0);
            if(genderF.equals(gender)){
                rankF += 1;
                if(rankF == rank){
                    return nameF;
                }                
            }
        }        
        return "NO NAME";           
    }
    
    public String whatIsNameInYear(String name, int year, int newYear, String gender){
        int rankOld = getRank(year, name, gender);
        String nameNew = getName(newYear, rankOld, gender);
        return nameNew;
    }
    
    public int yearOfHighestRank(String name, String gender){
        int highestRank = 0;
        int currRank = 0;
        int year = 0; 
        DirectoryResource dr = new DirectoryResource();        
        for(File f : dr.selectedFiles()){
            String yr = f.getName();            
            yr = yr.substring(3,7);
            int yearF = Integer.parseInt(yr);
//            System.out.println(yearF);
            currRank = getRank(yearF, name, gender);
            System.out.println(currRank);
            if(currRank != -1){
                if(highestRank == 0){
                    highestRank = currRank;
                    year = yearF;
                }
                else if(highestRank > currRank){
                    highestRank = currRank;
                    year = yearF;
                }
            }
        }
        
        return year;
    }
    
    public double getAverageRank(String name, String gender){
        int rank = 0;
        double count = 0;
        int rankF = 0;
        DirectoryResource dr = new DirectoryResource();
        for(File f : dr.selectedFiles()){
            String yr = f.getName();
            yr = yr.substring(3,7);
            int yearF = Integer.parseInt(yr);            
            rankF = getRank(yearF, name, gender);
            if(rankF != -1){
                rank += rankF;
                count += 1;            
            }               
        }
        return(rank/count);
    }
    
    public int getTotalBirthsRankedHigher(int year, String name, String gender){
        FileResource fr = new FileResource();
        int flag = 0;
        int higherthan = 0;
        for(CSVRecord rec : fr.getCSVParser(false)){
            String genderF = rec.get(1);
            String nameF = rec.get(0);
            if(flag == 0){
                if(genderF.equals(gender)){
                    String countS = rec.get(2);
                    int countF = Integer.parseInt(countS);
                    higherthan += countF;
                    if(nameF.equals(name)){
                        flag = 1;
                        higherthan -= countF;
                        break;
                    }
                }
            }            
        }
        return higherthan;
    }
    
    public void tester(){
        /*FileResource fr = new FileResource();
        totalBirths(fr);
        */
       //int a = getRank(1960, "Frank", "M");
       //String a = getName(1980, 450, "M");
       //String a = whatIsNameInYear("Owen", 1972, 2014, "M");
       int a = yearOfHighestRank("Mich", "M");
       //double a = getAverageRank("Robert", "M");
       //int a = getTotalBirthsRankedHigher(1990, "Drew", "M");
       System.out.println(a);
        
    }
}
