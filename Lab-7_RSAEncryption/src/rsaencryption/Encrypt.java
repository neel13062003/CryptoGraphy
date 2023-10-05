/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsaencryption;

/**
 *
 * @author user1
 */
public class Encrypt {
    String msg;
    String encryptedText;
    int p, q, n, e;
    Encrypt(String msg){
        this.msg = msg;
        p = 53;
        q = 59;
        n = p*q;
        e = 3;
    }
    public int doEncryption(){
        
        int key = 0;
        for(int i = 0;i < msg.length(); i++){
            key = key*10 + ((int)msg.charAt(i) - (int)'a' + 1);
        }
        int temp = key;
        key = 1;
        for(int i = 0; i < e;i++) key *= temp;
        
        return key%n;
    }
}
