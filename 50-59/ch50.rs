fn is_prime(n: u64) -> bool {

    if n == 0 || n == 1 {
        return false;
    }

    for i in 2..((n as f64).sqrt() as u64 + 1) {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

fn get_primes_below(n: u64) -> Vec<u64> {

    let mut i = 2;
    let mut primes = Vec::new();

    while i < n {
        if is_prime(i) {
            primes.push(i);
        }

        i += 1;
    }

    return primes;
}


fn largest_consecutive_prime_sum(primes: &[u64], n: usize, max: u64) -> Vec<u64> {

    let mut i = n;
    let mut j = n;

    while primes[n..i].iter().sum::<u64>() < max && i < primes.len() {
        if is_prime(primes[n..i].iter().sum()) {
            j = i;
        }

        i += 1;
    }

    Vec::from(&primes[n..j])
}

fn main() {

    let primes = get_primes_below(1000);
    let mut largest_suite = Vec::new();

    println!("{}", primes.len());

    for i in 0..primes.len() {

        let suite = largest_consecutive_prime_sum(&primes, i, 1000);

        if suite.len() > largest_suite.len() {
            largest_suite = suite;
            println!("New largest suite : {:?}", largest_suite);
        }
    }

    println!("Largest suite is {:?} (length = {}, sum = {})", largest_suite, largest_suite.len(), largest_suite.iter().sum::<u64>());
}
