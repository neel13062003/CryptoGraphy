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
public class Decrypt {
    public String doDecrypt(int key){
        int d = 2011;
        int n = 3127;
        int temp = 1;
        
        for(int i = 0;i < d;i++){
            temp = (temp * key) % n;
        }
        
        StringBuilder ans = new StringBuilder();
        
        while(temp != 0){
            int x = temp % 10;
            temp /= 10;
            ans.append((char)(x + 'a' - 1));
        }
        ans = ans.reverse();
        return ans.toString();
    }
}
