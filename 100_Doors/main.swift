
var doors = Array(repeating: false, count: 100)

// for i in 0...doors.count-1 {    
//     for j in 0...doors.count-1 {
//         doors[j]
//     }
// }

for i in 0...doors.count-1 {
    for j in stride(from: 0, to: doors.count-1, by: i) {
        print(doors[j])
        
    }
}