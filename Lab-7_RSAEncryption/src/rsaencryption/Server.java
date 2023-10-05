/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsaencryption;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author user1
 */
public class Server {
    public static void main(String[] args) {
        try{
            ServerSocket ss=new ServerSocket(9090);
            Socket s=ss.accept();
            System.out.println("Client Connected");
            
            InputStreamReader in=new InputStreamReader(s.getInputStream());
            BufferedReader br=new BufferedReader(in);
            
            String str=br.readLine();
            int key = Integer.valueOf(str);
            Decrypt d = new Decrypt();
            String plain = d.doDecrypt(key);
            
            System.out.println(plain);
            PrintWriter pw=new PrintWriter(s.getOutputStream());
            pw.println(plain);
            pw.flush();
        }catch(Exception e){}
        
    }
}
