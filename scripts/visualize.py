import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../logs/trades.csv")

print(df.head())

plt.figure(figsize=(10, 5))

plt.plot(df["order_id"], df["price"])

plt.title("Trade Price vs Order ID")

plt.xlabel("Order ID")

plt.ylabel("Price")

plt.grid(True)

plt.savefig("../logs/trade_plot.png")

print("Graph saved as trade_plot.png")
