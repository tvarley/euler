mod euler001;
mod euler002;
mod euler003;
mod euler004;
mod euler005;
mod euler006;

fn main() {
    println!("Hello, world!");
    println!("Euler001: {}", euler001::sum_natural_35(1000));
    println!("Euler002: {}", euler002::sum_even_fib(4_000_000));
    println!("Euler003: {}", euler003::largest_prime_factor(600_851_475_143));
    println!("Euler004: {}", euler004::prob004_brute_force());
    println!("Euler005: {}", euler005::prob005_brute_force(20));
    println!("Euler006: {}", euler006::sum_squares(100));
}
