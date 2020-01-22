use std::fs::File;
use std::io::prelude::*;

fn main() -> std::io::Result<()> {

    let mut file = File::open("p099_base_exp.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;

    let b: f64 = 1000.0;
    let mut highest_line = 0.0;
    let mut highest_line_exp = 0.0;

    for (line_number, line) in contents.lines().enumerate() {
        let values: Vec<f64> = line.split(",").map(|x| x.parse::<f64>().unwrap()).collect();
        let a = values[0];
        let n = values[1];

        // We search x s.t. b^x = a^n
        // So x = log_b(a^n) = n * log_b(a)
        let x = n * a.log(b);

        if x > highest_line_exp {
            highest_line_exp = x;
            highest_line = (line_number + 1) as f64;
        }
    }

    println!("Highest line is {}", highest_line);

    Ok(())
}
