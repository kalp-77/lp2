# Define the knowledge base
knowledge_base = {
    "APPLE": {
        "earnings_growth": 0.05,
        "revenue_growth": 0.02,
        "market_cap": 200000000000,
        "dividend_yield": 0.01
    },
    "GOOGLE": {
        "earnings_growth": 0.08,
        "revenue_growth": 0.05,
        "market_cap": 1200000000000,
        "dividend_yield": 0.00
    },
    "AMAZON": {
        "earnings_growth": 0.06,
        "revenue_growth": 0.10,
        "market_cap": 1500000000000,
        "dividend_yield": 0.00
    }
}


# Define the inference engine
def evaluate_stock(stock):
    score = 0
    if knowledge_base[stock]["earnings_growth"] > 0.05:
        score += 1
    if knowledge_base[stock]["revenue_growth"] > 0.05:
        score += 1
    if knowledge_base[stock]["market_cap"] > 1000000000000:
        score += 1
    if knowledge_base[stock]["dividend_yield"] > 0.01:
        score -= 1

    if score >= 3:
        print("Score = ", score)
        print(f"{stock} is a good buy (based on rule-based evaluation).")

    elif 2 <= score < 3:
        print("Score = ", score)
        print(f"{stock} is good to hold (based on rule-based evaluation).")

    else:
        print("Score = ", score)
        print(f"{stock} is not a good buy (based on rule-based evaluation).")


while True:
    # Get user input
    stock_symbol = input("Enter a stock symbol: ")

    # Test the system
    evaluate_stock(stock_symbol)

    x = input("Do you want to continue: (Y or N)")
    if x == "Y" or x == 'y':
        continue
    elif x == "N" or x == 'n':
        break
    else:
        print("please enter valid input")
