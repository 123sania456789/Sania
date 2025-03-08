package cse.cambridge.second;
import org.apache.commons.lang3.StringUtils;
/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
    	String text="Hello world"; 
    	String t="sania";
        System.out.println( "Trimmed: " + StringUtils.trim(text) );
        System.out.println("Is Empty: "+ StringUtils.isEmpty(""));
        System.out.println("starts with: "+ StringUtils.startsWith(text,t));
        System.out.println("ends with: "+ StringUtils.endsWith(text,t));
        System.out.println("equals: "+ StringUtils.equals(text,t));
    }
}

/*
Trimmed: Hello world
Is Empty: true
starts with: false
ends with: false
equals: false
*/
