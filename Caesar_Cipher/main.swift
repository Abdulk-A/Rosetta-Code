//
//  MainView.swift
//  CryptographyApp
//
//  Created by Abdullah Abdulkareem on 5/2/24.
//

import SwiftUI

extension MainView{
    @Observable class ViewModel {
        var cipher = ""
        
        func encode() -> String {
            if cipher.count > 0 {
                var rand = Int.random(in: 0...25)
                for i in 0..<cipher.count {
                    let j = cipher.index(cipher.startIndex, offsetBy: i)
                    let c = Character(UnicodeScalar(32))
                    
                    cipher.replaceSubrange(j...j, with: c)
                }
            }
            
            return ""
        }
    }
}

struct MainView: View {
    
    @State private var vm = ViewModel()
    
    var body: some View {
        VStack{
            
            HStack {
                TextField("Please enter something to encode", text: $vm.cipher)
                
                Button("Encode") {vm.encode()}
                    .padding(9)
                    .background(.blue)
                    .foregroundStyle(.white)
                    .clipShape(.capsule)
            }
        }
        .padding()
    }
}

#Preview {
    MainView()
}
