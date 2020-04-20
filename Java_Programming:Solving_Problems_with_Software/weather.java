import edu.duke.*;
import java.io.File;
import org.apache.commons.csv.*;
/**
 * Write a description of weather here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class weather { 
    
    public CSVRecord lowest(CSVParser parser, String col){
        CSVRecord minRow = null;
        for( CSVRecord record : parser ){
            String currValue = record.get(col);
            if(!currValue.equals("N/A")){
                //System.out.println(currValue);
                double currT = Double.parseDouble(currValue);            
                if((minRow == null) && (currT > -9999)){
                    minRow = record;
                }
                double minT = Double.parseDouble(minRow.get(col));
                if((minT > currT) && (currT > -9999)){
                    minRow = record;
                }            
            }
        }        
        return minRow;
    }
    
    public CSVRecord coldestHourInFile(CSVParser parser){
        return lowest(parser, "TemperatureF");
    }
    
    public String fileWithColdestTemperature(){
        CSVRecord minRow = null;
        String filename = "";
        DirectoryResource dr = new DirectoryResource();
        for(File f : dr.selectedFiles()){
            FileResource fr = new FileResource(f);
            CSVRecord curr = coldestHourInFile(fr.getCSVParser());
            double currT = Double.parseDouble(curr.get("TemperatureF"));            
            if((minRow == null) && (currT > -9999)){
                minRow = curr;
                filename = f.getName();
            }
            double minT = Double.parseDouble(minRow.get("TemperatureF"));
            if((minT > currT) && (currT > -9999)){
                minRow = curr;
                filename = f.getName();                
            }
        }
        return filename;
    }
    
    public CSVRecord lowestHumidityInFile(CSVParser parser){
        return lowest(parser, "Humidity");
    }
    
    public CSVRecord lowestHumidityInManyFiles(){
        CSVRecord minRow = null;
        DirectoryResource dr = new DirectoryResource();
        for(File f : dr.selectedFiles()){
            FileResource fr = new FileResource(f);
            CSVRecord curr = lowestHumidityInFile(fr.getCSVParser());
            String currValue = curr.get("Humidity");
            //System.out.println(f.getName());
            if(currValue != "N/A"){
                double currT = Double.parseDouble(currValue);            
                if((minRow == null)){
                    minRow = curr;
                }
                double minT = Double.parseDouble(minRow.get("Humidity"));
                if((minT > currT)){
                    minRow = curr;              
                }
            }                    
        }
        return minRow;
    }
    
    public double averageTemperatureInFile(CSVParser parser){
        double sumT = 0.0;
        int countT = 0;
        for( CSVRecord record : parser ){
            String currValue = record.get("TemperatureF");            
            double currT = Double.parseDouble(currValue);            
            if(currT > -9999){
                sumT = sumT + currT;
                countT = countT +1;
            }               
        }
        return (sumT/countT);
    }
    
    public double averageTemperatureWithHighHumidityInFile(CSVParser parser, int value){
        double sumT = 0.0;
        int countT = 0;
        for( CSVRecord record : parser ){
            String currValue = record.get("Humidity");
            if(!currValue.equals("N/A")){
                double currT = Double.parseDouble(record.get("TemperatureF"));            
                if(currT > -9999){
                    sumT = sumT + currT;
                    countT = countT + 1;
                }               
            }
        }
        return (sumT/countT);
    }
    
    public void testColdestHourInFile(){
        FileResource fr = new FileResource();
        CSVParser p = fr.getCSVParser();
        CSVRecord a = coldestHourInFile(p);
        System.out.println(a.get("TemperatureF"));
        /*CSVRecord ans = lowestHumidityInFile(p);
        System.out.println(ans.get("TemperatureF"));
        */
        
        /*String a = fileWithColdestTemperature();
        System.out.println(a);
        *///System.out.println(a.get("DateUTC"));
    }
}
