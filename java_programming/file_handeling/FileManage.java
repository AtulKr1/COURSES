package file_handeling;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

class FileManage {
    public static void main(String[] args) {
        File fobj = new File("./file_handeling/file.txt");
        if (fobj.exists()) {
            System.out.println("File Name: " + fobj.getName());
            System.out.println("Writable: " + fobj.canWrite());
            System.out.println("Readable " + fobj.canRead());

            try {
                FileWriter fwrite = new FileWriter(fobj);
                fwrite.write("Hello, My name is Apple Mango\n");

                fwrite.close();
            } 
            catch (Exception e) {
                System.out.println(e);
            }

            try {  
                Scanner dataReader = new Scanner(fobj);  
                while (dataReader.hasNextLine()) {  
                    String fileData = dataReader.nextLine();  
                    System.out.println(fileData);  
                }  
                dataReader.close();  
            }
            catch (Exception e) {  
                System.out.println(e);  
            }  
        } 
        else {
            System.out.println("The file does not exist.");
        }
    }
}