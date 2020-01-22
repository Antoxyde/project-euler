use std::collections::HashSet;

pub fn main() {

    let mut s = HashSet::new();

    let n  = 2.0;

    for a in 2..=100 {
        for b in 2..=100 {
            let x = (b as f64) * (a as f64).log(n);
            s.insert((x * 100_000_000.0) as u64);
        }
    }

    println!("{}", s.len());
}
