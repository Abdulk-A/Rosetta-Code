//
//  MainView.swift
//  CryptographyApp
//
//  Created by Abdullah Abdulkareem on 5/2/24.
//

import SwiftUI

extension CaesarCipherView{
    @Observable class ViewModel {
        var cipher = ""
        var encoded = ""
        func encode() {
            if cipher.count > 0 {
                let rand = Int.random(in: 0...25)
                for i in 0..<cipher.count {
                    let j = cipher.index(cipher.startIndex, offsetBy: i) //getting string.index of current i
                    
                    let ch = cipher[j]
                    
                    
                    if let chVal = ch.asciiValue {
                        if chVal >= 65 && chVal <= 90 && Int(chVal) + rand > 90 {
                            //x = 90 - ascii
                            //rem = rand - x
                            //65 + rem
                            
                            let rem = 64 + (rand - (90 - Int(chVal)))

                            cipher.replaceSubrange(j...j, with: String(UnicodeScalar(UInt8(rem))))
                            
                            
                        }
                        else if chVal >= 97 && chVal <= 122 && Int(chVal) + rand > 122 {
                            let rem = 96 + (rand - (122 - Int(chVal)))
                            cipher.replaceSubrange(j...j, with: String(UnicodeScalar(UInt8(rem))))
                        }
                        else {
                            cipher.replaceSubrange(j...j, with: String(UnicodeScalar(UInt8(chVal) + UInt8(rand))))
                        }
                        
                    }
                }
            }
            encoded = cipher
            cipher = ""
        }
    }
}

struct CaesarCipherView: View {
    
    @State private var vm = ViewModel()
    
    var body: some View {
        VStack{
            
            HStack {
                TextField("Please enter something to encode", text: $vm.cipher)
                    .padding(9)
                    .background(.gray.opacity(0.5))
                    .clipShape(.capsule)
                
                Button("Encode") {
                    vm.encode()
                }
                    .padding(9)
                    .background(.blue)
                    .foregroundStyle(.white)
                    .clipShape(.capsule)
                

            }
            Text(vm.encoded)
                .font(.title)
        }
        .padding()
        Spacer()
    }
}

#Preview {
    CaesarCipherView()
}
