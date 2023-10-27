fn main() {
    let mut elements: [i32; 5] = [1, 4, 0, -32, 10];
    let n = 5;
    for i in 1..n {
        let key = elements[i];
        let mut j = i - 1;
        loop {
            if key >= elements[j] {
                j += 1;
                break;
            }
            elements[j + 1] = elements[j];
            if j == 0 {
                break;
            };
            j -= 1;
        }
        elements[j] = key;
    }
    dbg!(elements);
}
