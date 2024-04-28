import UIKit

//100 doors

var prisoners = [Int]()
var cards = [Int]()

let n: Int = 99

for i in 0...n {
    cards.append(i)
}

func playSmart(_ cards: [Int], _ n: Int) -> Bool {
    
    for i in 0...n {
        var k = i
        var sucess: Bool = false
        for j in 1...50 {
            if(cards[k] == i) {
                sucess = true
                break
            }
            else { k = cards[k] }
        }
        if(!sucess) {return false}
    }
    
    return true
}

var successCount: Int = 0

for i in 1...100 {
    cards.shuffle()
    if(playSmart(cards, n)) {successCount += 1}
}

print(successCount)
