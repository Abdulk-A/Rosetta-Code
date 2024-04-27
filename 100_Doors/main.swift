//swift in xcode playground

let n: Int = 100
var doors = Array(repeating: false, count: n)

for i in 1...n {
    for j in stride(from: i - 1, to: n, by: i) {
        doors[j].toggle()
    }
}

//print

for i in doors {
    print(i)
}

//or print like this

for (i, j) in doors.enumerated() {
    print("door \(i + 1) is \(j ? "open" : "closed")")
}
