package testcode;

public class RemoveLeadingZero {
	
	// to Remove leading zeros
    public static String removeZero(String str)
    {
    	//find last position of leading zeros
    	int pos = 0;
        while (pos < str.length() && str.charAt(pos) == '0')
            pos++; 
        StringBuffer sb = new StringBuffer(str);
        
        //Replacing substring from index 0 to index pos
        sb.replace(0, pos, "");
        return sb.toString();
    }
 
    public static void main(String[] args)
    {
        // Sample string input
        String str = "0008720";
        str = removeZero(str);
        System.out.println(str);
    }
}
