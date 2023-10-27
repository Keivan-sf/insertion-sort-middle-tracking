fn main() {
    let mut elements: [i32; 5] = [1, 4, 0, -32, 10];
    let n = 5;
    sort(&mut elements, n);
    dbg!(elements);
}

fn sort(list: &mut [i32], n: usize) {
    for i in 1..n {
        let key = list[i];
        let mut j = i - 1;
        loop {
            if key >= list[j] {
                j += 1;
                break;
            }
            list[j + 1] = list[j];
            if j == 0 {
                break;
            };
            j -= 1;
        }
        list[j] = key;
    }
}
