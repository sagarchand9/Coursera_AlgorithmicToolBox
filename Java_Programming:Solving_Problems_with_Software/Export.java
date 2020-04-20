import edu.duke.*;
import org.apache.commons.csv.*;

/**
 * Write a description of Export here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Export {
    
    public String countryInfo(CSVParser parser, String country){
        for(CSVRecord record : parser){
            if(record.get("Country").equals(country)){  
                String exports = record.get("Exports");
                String value = record.get("Value (dollars)");
                return country + ": " + exports + ": " + value;
            }
        }
        return "NOT FOUND";
    }
    
    public void listExportersTwoProducts(CSVParser parser, String exportItem1, String exportItem2){
        for(CSVRecord record : parser){
            String exportItems = record.get("Exports");
            if((exportItems.contains(exportItem1))&&(exportItems.contains(exportItem2))){            
                System.out.println(record.get("Country"));
            }
        }
    }
    
    public int numberOfExporters(CSVParser parser, String exportItem){
        int count = 0;
        for(CSVRecord record : parser){
            String exportItems = record.get("Exports");
            if(exportItems.contains(exportItem)){
                count = count + 1;
            }
        }
        System.out.println(count);
        return count;
    }
    
    public void bigExporters(CSVParser parser, String amount){
        for(CSVRecord record : parser){
            String value = record.get("Value (dollars)");
            if(value.length() > amount.length()){
                System.out.println(record.get("Country") + " " + value);
            }
        }
    }
    
    public void tester(){
        FileResource fr = new FileResource();
        CSVParser parser = fr.getCSVParser();        
       bigExporters(parser, "$999,999,999,999");

    }

}
