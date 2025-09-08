# ## Properties of the Greatest Common Divisor (GCD)

A collection of important properties and identities related to the GCD of integers.

---

### ## Fundamental Definitions & Properties

* **Definition**: For two integers `a` and `b`, not both zero, the `gcd(a, b)` is the largest positive integer that divides both `a` and `b`.

* **Common Divisor Property**: Every common divisor of `a` and `b` is also a divisor of `gcd(a, b)`.

* **Bézout's Identity**: The `gcd(a, b)` is the smallest positive integer `d` that can be expressed as a linear combination of `a` and `b`.
    $d = a \cdot p + b \cdot q$
    where `p` and `q` are integers.

* **Commutativity**: The order of arguments does not matter.
    $gcd(a, b) = gcd(b, a)$

* **Associativity**: The GCD of three or more numbers can be calculated by taking the GCDs of pairs.
    $gcd(a, b, c) = gcd(a, gcd(b, c)) = gcd(gcd(a, b), c)$

* **Identity with Zero**: The GCD of any non-zero number `a` and `0` is the absolute value of `a`.
    $gcd(a, 0) = |a|$

---

### ## Euclidean Algorithm & Related Identities

* **Euclidean Algorithm Recurrence**: This is the core of the most efficient algorithm for computing GCD.
    $gcd(a, b) = gcd(b, a \pmod b)$

* **Invariance with Addition**: Adding a multiple of one number to the other does not change the GCD.
    $gcd(a, b) = gcd(a + m \cdot b, b)$

* **GCD of `n` and `n+1`**: The GCD of any two consecutive integers is **1**. They are always coprime.
    $gcd(n, n+1) = 1$
    * **Proof**: Let `d` be a common divisor of `n` and `n+1`. Then `d` must also divide their difference, which is `(n+1) - n = 1`. The only positive divisor of 1 is 1, so `d=1`.

---

### ## Multiplicative & Divisive Properties

* **Distributive Property**:
    $gcd(m \cdot a, m \cdot b) = |m| \cdot gcd(a, b)$

* **Coprime Property Derivation**: An important consequence is that you can "factor out" the GCD. If `g = gcd(a, b)`, then `a/g` and `b/g` are coprime.
    $gcd(a/g, b/g) = 1$
    * **Derivation**: We know `gcd(g \cdot (a/g), g \cdot (b/g)) = g \cdot gcd(a/g, b/g)`. Since the left side is `gcd(a, b) = g`, we have `g = g \cdot gcd(a/g, b/g)`, which implies `gcd(a/g, b/g) = 1`.

* **Division Property**:
    $gcd(a/m, b/m) = gcd(a, b) / m$, where `m` is a common divisor of `a` and `b`.

* **Euclid's Lemma Extension**: If `a` divides `b*c` and `gcd(a, b) = d`, then `a/d` divides `c`.

* **Coprimality with a Product**: A number `a` is coprime to a product `b*c` if and only if it is coprime to each factor.
    $gcd(a, b \cdot c) = 1 \iff gcd(a, b) = 1 \text{ and } gcd(a, c) = 1$

---

### ## Relationship with LCM & Prime Factorization

* **GCD and LCM Relation**: The product of the GCD and LCM of two numbers is equal to the absolute value of their product.
    $gcd(a, b) \cdot lcm(a, b) = |a \cdot b|$

* **Prime Factorization Method**: If the prime factorizations are $a = p_1^{e_1} \cdot p_2^{e_2} \cdots p_k^{e_k}$ and $b = p_1^{f_1} \cdot p_2^{f_2} \cdots p_k^{f_k}$, then:
    $gcd(a, b) = p_1^{\min(e_1, f_1)} \cdot p_2^{\min(e_2, f_2)} \cdots p_k^{\min(e_k, f_k)}$

* **Distributivity with LCM**:
    $gcd(a, lcm(b, c)) = lcm(gcd(a, b), gcd(a, c))$
    $lcm(a, gcd(b, c)) = gcd(lcm(a, b), lcm(a, c))$

---

### ## Advanced & Special Properties

* **Geometric Interpretation**: In a Cartesian coordinate system, `gcd(a, b)` is the number of segments between integer-coordinate points on the line segment connecting `(0, 0)` and `(a, b)`.

* **Powers Identity**: For non-negative integers `n, a, b` where `n > 1`:
    $gcd(n^a - 1, n^b - 1) = n^{gcd(a, b)} - 1$

* **Fibonacci Identity**: The GCD of two Fibonacci numbers is the Fibonacci number of the GCD of their indices.
    $gcd(F_a, F_b) = F_{gcd(a, b)}$

* **Euler's Totient Identity**: The GCD of `a` and `b` can be expressed as the sum of the values of Euler's totient function `φ(k)` for all common divisors `k` of `a` and `b`.
    $gcd(a, b) = \sum_{k | a \text{ and } k | b} \phi(k)$
