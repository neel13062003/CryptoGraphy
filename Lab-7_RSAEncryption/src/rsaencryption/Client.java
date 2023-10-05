/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsaencryption;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 *
 * @author user1
 */

public class Client {
    
    public static void main(String[] args) {
        try{
            Socket s=new Socket("localhost",9090);
            PrintWriter pw=new PrintWriter(s.getOutputStream());
            Scanner input = new Scanner(System.in);
            System.out.println("write the string");
            String str1 = input.next();
            
            Encrypt e = new Encrypt(str1);
            int encrptedKey = e.doEncryption();
            
            pw.println(encrptedKey);
            
            pw.flush();
            InputStreamReader in=new InputStreamReader(s.getInputStream());
            BufferedReader br=new BufferedReader(in);
            String str=br.readLine();
            System.out.println(str.toString());
            pw.println("Hello Server");
        }catch(Exception e){}
    }
}
