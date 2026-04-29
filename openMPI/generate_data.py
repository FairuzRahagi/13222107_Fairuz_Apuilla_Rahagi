import random
import time

configs = [
    ("data_10000.txt",    10_000),
    ("data_100000.txt",  100_000),
    ("data_1000000.txt", 1_000_000),
]

random.seed(42)   # reproduktibel

for filename, n in configs:
    t0 = time.time()
    print(f"Membuat {filename} ({n:,} angka) ... ", end="", flush=True)
    with open(filename, "w") as f:
        for i in range(n):
            f.write(f"{random.uniform(-1_000_000.0, 1_000_000.0):.6f}\n")
    print(f"selesai ({time.time()-t0:.2f}s)")

print("\nSemua file berhasil dibuat.")
