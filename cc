#A Simple client class that generates private and public key by using built-in python RSA algorithm and test it.

'''Key generation – public and private
Choose 2 large prime nos P &amp; Q.
Calculate N = P * Q
Select the public key (i.e. the encryption key) E such that is not a factor of (P-1) and (Q-1).'''

from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

#generate RSA key pair
key = RSA.generate(2048)

private_key = key
public_key = key.publickey()

#create cipher objects
encryptor = PKCS1_OAEP.new(public_key)
decryptor = PKCS1_OAEP.new(private_key)

#message to encyrpt
message= b"Hello RSA!"

#encrypt 
encrypted = encryptor.encrypt(message)
print("Encrypted", encrypted)

#decrypt
decrypted = decryptor.decrypt(encrypted)
print("Decrypted", decrypted.decode())

#------A Simple client class that generates private ledgers and public key ledgers by using built-in python RSA algorithm and test it.

import binascii
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from Crypto import Random


class Client:
    def __init__(self):
        random = Random.new().read
        self._private_key = RSA.generate(1024, random)
        self._public_key = self._private_key.publickey()
        self.signer = PKCS1_v1_5.new(self._private_key)


    @property
    def identity(self):
        return binascii.hexlify(
            self._public_key.export_key(format="DER")
        ).decode("ascii")


TYSD = Client()
print("\nPublic Key:", TYSD.identity)

#-------RSA using Manual way.

p=3
q=11
n=p*q
phi=(p-1)*(q-1)
e = 7
d = 3

def encrypt(m):
    return(m**e)%n

def decrypt(c):
    return(c**d)%n

message = 4
print("Original message:",message)

encrypted = encrypt(message)
print("Encrypted message:",encrypted)
 
decrypted = decrypt(encrypted)
print("Decrypted message:",decrypted)

_______________________________________

#Find the exchange rate of cryptocurrency with necessary data
Go to Coin Gecko


P1 = Price on the First Day
PN = Price on the Last Day
Final Change (%) = PN-P1 / P1 * 100
LOG Return R = LN (PN/P1) * 100

Bitcoin:
P1 = 86,972.85
PN = 68,567.68
Final change = 68,567.68-86,972.85 / 86,972.85 * 100 =
−0.211613×100
= −21.16%
LOG Return R = −23.76%

Calculate the same way for others too like Ethereum, Tether, Solana, DogeCoin


_______________________
#Finding Number of Bitcoins by applying the equation over a defined value.

#No. of btc = amt in inr / price of 1 btc in inr

investment = float(input("Enter the initial investment amount: "))
btc_price = float(input("Enter the current price of Bitcoin (BTC): "))

btc_amount = investment / btc_price
print(f"You will get {btc_amount:.8f} BTC")

#------A transaction class to send and receive money and test it.

'''> ACCOUNT CREATE
> USE DEPOSIT = SELFBAL + AMT
> USE WITHDRAW = SELFBAL - AMT
> ENQUIRY
'''
class BankAccount:
    def __init__(self, account_holder, initial_balance=0):
        self.account_holder = account_holder
        self.balance = initial_balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited: ${amount:.2f}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew: ${amount:.2f}")
        else:
            print("Insufficient funds or invalid withdrawal amount.")

def enquiry(account):
    print(f"Account Holder: {account.account_holder}")
    print(f"Current Balance: ${account.balance:.2f}")

# Example usage
account = BankAccount("Peehul", 1000)
account.deposit(500)
account.withdraw(200)
enquiry(account)

__________________________________

Setting up Ethereum development Environment.
S1: search for ethereum downloads, go to fist link and click on for Windows
S2: After that, click on it > check the Development Tool Too.
S3: Go to path and open cmd and give command.
-> geth version
S4: search for ganache downloads, go to fist link and click on for Download (Windows).
S5: Open and click on Install
S6: Click on continue and Quickstart. Use any these account to do a transation.
S7: search for metamask downloads, go to fist link and click on Start swipping.
S8: Browser Extension > Chrome > Add Chrome
S9: Click on create a new wallet
S10: then continue with Use Secret recovery phase.
S11: Setup a Password
S12: Choose both the checkboxes > and continue.
S13: open wallet.
_______________________________________
Open both MetaMask and Ganache.
In MetaMask, click on the three horizontal lines located on the right side of the interface and navigate to “Networks.”

Select “Add a Custom Network.”
Enter the following details:
Network Name:Localhost8545
Chain ID:1337
Currency Symbol:ETH
For the Default RPC URL, click on the dropdown button next to the field and select “Add RPC URL.”

Open Ganache, locate the RPC Server address displayed in the menu bar, and copy the link.
Paste the copied RPC Server URLinto the RPC URL field in MetaMask, then click “Add URL.”

In MetaMask, locate the “Imported Account” section on the left-hand side and click on it.
Select “Add Wallet” then choose “Import an Account.”

Return to Ganache and click on the key iconnext to any account. Copy the private key displayed.
Paste the copied private key into MetaMask and click “Import.”

After importing, the account will display a balance of 100 Ethereum (ETH).
Navigate back to the MetaMask home pageand click on “Send.”
From the network dropdown, select “Localhost 8545.”
Choose the available Ethereum balanceand click on it.
Click the address book icon and select any wallet. Enter the desired amount in the Amountfield.
Click “Continue” and then select “Confirm” to proceed with the transaction.

Once the transaction is completed, a confirmation message indicating that the transaction was successful will appear.
In Ganache, the account from which the transaction was made will reflect the reduced balance, confirming that the transfer has been processed.
________________________________
_______________________________
_____________________________________-

# remix ide use cases
'''>Remix IDE on google
>Write a program in a new file - Donation.sol
>Compile it
>Deploy it
>Copy 1st Address & Paste to deploy
>Transaction will happen

''H. Donation: 1. Set Value to 1 Ether, click donate.
2. Click total to see the accumulated amount.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Donation {
    uint public total;

    function donate() public payable {
        total += msg.value;
    }

    function getBalance() public view returns(uint) {
        return address(this).balance;
    }
}
#-----Same steps for Piggy Bank (PiggyBank.sol)
'''F. Piggy Bank: 1. Send money using the low-level "Transact" button at the very bottom (calls receive).
2. Click withdraw. Only the account that deployed the contract can do this.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract PiggyBank {

    function deposit() public payable {}

    function getBalance() public view returns(uint) {
        return address(this).balance;
    }

    function withdraw() public {
        (bool success, ) = payable(msg.sender).call{value: address(this).balance}("");
        require(success, "Failed");
    }
}

#Auction
'''A. Auction: 1. Select Account 1, set Value to 1 Ether, click bid.
2. Switch to Account 2, set Value to 2 Ether, click bid.
3. Check highestBidder—it should now be Account 2.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract SimpleAuction {
    address public highestBidder;
    uint public highestBid;

    function bid() public payable {
        // Error check: bid must be higher than the current highest
        require(msg.value > highestBid, "Bid is too low.");

        // Refund the previous highest bidder
        if (highestBid != 0) {
            payable(highestBidder).transfer(highestBid);
        }

        highestBidder = msg.sender;
        highestBid = msg.value;
    }
}

#Deposit & Withdraw
'''
B. Deposit & Withdraw: 1. Set Value to 5 Ether, click deposit.
2. Click getMyBalance (blue button) to see your 5 ETH.
3. Type 2000000000000000000 (2 ETH in Wei) into the withdraw box and click it.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Bank {
    mapping(address => uint) public balances;

    function deposit() public payable {
        balances[msg.sender] += msg.value;
    }

    function withdraw(uint _amount) public {
        require(balances[msg.sender] >= _amount, "Insufficient balance");
        
        balances[msg.sender] -= _amount;
        payable(msg.sender).transfer(_amount);
    }

    function getMyBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}

#Voting
'''C. Voting: 1. Select Account 1, type 1 in the box, click vote.
2. Try clicking vote again with the same account—Remix will show a Red Error in the console because of the require statement (this is a successful test!).
3. Switch to Account 2 to cast a second vote.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Voting {
    uint public candidate1Count;
    uint public candidate2Count;
    mapping(address => bool) public hasVoted;

    function vote(uint _candidate) public {
        require(!hasVoted[msg.sender], "You have already voted.");
        require(_candidate == 1 || _candidate == 2, "Invalid candidate.");

        if (_candidate == 1) {
            candidate1Count++;
        } else {
            candidate2Count++;
        }

        hasVoted[msg.sender] = true;
    }
}

#Attendance
'''D. Attendance: 1. Click markPresent.
2. Switch accounts and click it again.
3. Click totalAttendance to see the list growing.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Attendance {
    address[] public list;

    function markPresent() public {
        list.push(msg.sender);
    }

    function totalAttendance() public view returns (uint) {
        return list.length;
    }
}

#Quiz
'''E. Quiz: 1. Type "Paris" (with quotes) into the submitAnswer box.
2. Click the button.
3. Click solved and paste your address to see if it returns true.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Quiz {
    string public question = "What is the capital of France?";
    string private answer = "Paris";
    mapping(address => bool) public solved;

    function answerQuiz(string memory _attempt) public {
        // keccak256 is used to compare strings in Solidity
        if (keccak256(abi.encodePacked(_attempt)) == keccak256(abi.encodePacked(answer))) {
            solved[msg.sender] = true;
        }
    }
}

#Tranfer Ethereum one acc -> another
'''G. Transfer ETH: 1. Copy the address of Account 3 from the dropdown.
2. Paste it into the _receiver box of Account 1.
3. Set Value to 1 Ether and click sendMoney.'''
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract TransferEth {
    function sendMoney(address payable _receiver) public payable {
        _receiver.transfer(msg.value);
    }
}

________________________________________
# Interaction with smart contract and web 3
'''Prac 9 -

Interaction with smart contract and Web 3

STEPS:

Open ganache > quickstart

Metamask > networks > add a custom network

1.Network Name-Localhost 8545
2. Default RPC URL -take rpc url from ganache(rpc server copy paste) 
And add name ganache
3.Chain ID- 1337
4.Currency symbol-ETH
 
Save it.

Click on add wallet > import an account.
Go to any address in ganache > click on its key icon > copy the private key.
Paste the private key in add wallet. > And import. > Switch to this imported wallet.

Go to control panel > programs and features > check node.js version. (uninstall if not 16)
Version should be 16. Go to official node.js site and download 16. Version in .msi 
Set up node.js and install checking all the boxes and agreements. Finish the installation.

Next create a folder called blockchain and open it in VS code.
VS Code > Open New terminal > start typing command:
npm init -y
npm install -g truffle
npm install truffle lite-server
npx truffle init

Next in your vs code folder blockchain> go to folder- contracts > create file add.sol
add.sol:
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Add{
    function add(uint a, uint b) public pure returns (uint)
    {
        return a+b;
    }
}

Then in your folder migrations > create file 1_deploy.js

1_deploy.js:
const Add = artifacts.require("Add");


module.exports = function (deployer) {
  deployer.deploy(Add);
};

Then go to your file truffle-config.js
Around line 60 copy paste this for networks :
  networks: {
    // Useful for testing. The `development` name is special - truffle uses it by default
    // if it's defined here and no other network is specified at the command line.
    // You should run a client (like ganache, geth, or parity) in a separate terminal
    // tab if you use this network and you must also set the `host`, `port` and `network_id`
    // options below to some value.
    //
    development: {
    host: "127.0.0.1",     // Localhost (default: none)
    port: 7545,            // Standard Ethereum port (default: none)
    network_id: "*",       // Any network (default: none)
    },


And around line 107 change:
compilers: {
    solc: {
      version: "0.8.0",      // Fetch exact version from solc-bin (default: truffle's version)
      // docker: true,


Then in yout terminal write commands:
npx truffle compile --all
(Should show compiles contract successfully)
npx truffle migrate --reset
(Should show the 1_deploy.js file getting deployed and a contract address- thats the output.
ACCOUNT should be the one which you imported in metamask)
Then go to metamask > your imported account > some 0.01 eth should be deducted.'''

__9

'''Summary Steps
>Login to Metamask
>Start Ganach> quick start
>In metamask> Custom Network> Add RPC Host address & Local Address name
>Import Wallet
>add address/private key from ganache > import

> Uninstall node js 24
> install node 16.20.2
>open vscode > a newfolder “Blockchain”
>cmd 
Npm init -y
Npm i -g truffle
Npm i truffle lite-server
>changes in version and rpc port address
Npx truffle init
Npx truffle compile  –-all
Npx truffle migrate –reset

>Blockchain Folder> contracts> create 2 file named - 1_deploy.js & Add.sol'''

#1_deploy.js 
const Add = artifacts.require("Add");


module.exports = function (deployer) {
  deployer.deploy(Add);
};

#Add.sol
// SPDX-License-Identifier: MIT

pragma solidity ^0.8.0;

contract Add {
    function add(uint a, uint b) public pure returns (uint) {
        return a + b;
    }
}
____________________________



PRAC 7-
Prac 7-

A. Create a smart contract using ERC (DEFI).

Go to remix IDE.
Create a new workspace > blank > and name it ERC.
Create a file in your workspace and write the code.
Next compile the code, and then click on deploy.
And also copy the first account address.
Then go to deployed contracts > BalanceOF > Paste first account address > call
The uint amount appearing is the output.
MyToken.sol:

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract mytok is ERC20{
    constructor() ERC20("mytok", "MTK") {
        _mint(msg.sender, 2_000_000 ether);
    }
}

B. Stake a ethereum using address token (DEFI application).
Go to remix IDE.
Create a new workspace > blank > and name it ERC.
Create a file in your workspace and write the code.
Next compile > go to deploy and run > to click on deploy you have to give an address in address_ token
Copy paste 1st address in address_token > deploy
Then in deployed contracts > go to your deployed one > click on token.
Output : Your pasted address should show
SimpleStaking.sol:
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;
import "https://github.com/OpenZeppelin/openzeppelin-contracts/blob/v4.9.3/contracts/token/ERC20/ERC20.sol";

contract SimpleStaking {
    IERC20 public token;
    mapping(address => uint256) public stakes;

    constructor(address _token) {
        token = IERC20(_token);
    }

    function stake(uint256 amount) external {
        require(amount > 0, "Zero amount");
        token.transferFrom(msg.sender, address(this), amount);
        stakes[msg.sender] += amount;
    }

    function unstake(uint256 amount) external {
        require(stakes[msg.sender] >= amount, "Not enough stake");
        stakes[msg.sender] -= amount;
        token.transfer(msg.sender, amount);
    }
}



PRAC 6-
Practical 7 (in this prac only 1 account needs to be used)

7A
Ethereum in finance (defi)

Create a basic defi application
CREATING A SMART CONTRACT USING ERC (DEFI)

Open Remix IDE → Create new blank workspace (name it "erc")
Create new file → name it Mytoken.sol

CODE FOR MyToken : 

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract MyToken is ERC20 {
    constructor() ERC20("MyToken", "MTK") {
        _mint(msg.sender, 1_000_000 ether);
    }
}

'''Go to Solidity Compiler → Click Compile Mytoken.sol
Go to Deploy & Run Transactions
Make sure Account 1 is selected
Click Deploy
Scroll down in Deployed Contracts → 
click balanceOf → paste Account 1's address → shows big number
Click totalSupply -> should show same big number'''

7B

STAKE AN ETHEREUM USING ADDRESS TOKEN (DEFI)

In the same workspace, create a new file → name it Stake.sol

CODE FOR Stake :

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

import "@openzeppelin/contracts/token/ERC20/IERC20.sol";

contract SimpleStaking {
    IERC20 public token;
    mapping(address => uint256) public stakes;

    constructor(address _token) {
        token = IERC20(_token);
    }

    function stake(uint256 amount) external {
        require(amount > 0, "Zero amount");
        token.transferFrom(msg.sender, address(this), amount);
        stakes[msg.sender] += amount;
    }

    function unstake(uint256 amount) external {
        require(stakes[msg.sender] >= amount, "Not enough stake");
        stakes[msg.sender] -= amount;
        token.transfer(msg.sender, amount);
    }
}

'''Go to Solidity Compiler → Click Compile Stake.sol
Go to Deploy & Run Transactions
Then copy that 99.999 wala account ka address > paste it in _token, which is under deploy and click on transact 

Then scroll down, under SIMPLESTAKING > click on token 

The address there should be the same address which was paster under deploy in _token'''


added



PRAC 10-
Add this code too for 10 ka backup
app.js
async function addAndPay() {


if (typeof window.ethereum === 'undefined') {
    alert("MetaMask not detected!");
    return;
}

try {

    // Read numbers from UI
    const num1 = Number(document.getElementById("num1").value);
    const num2 = Number(document.getElementById("num2").value);

    const sum = num1 + num2;

    document.getElementById("result").innerText = "Result: " + sum;

    // Connect wallet
    await window.ethereum.request({ method: 'eth_requestAccounts' });

    const provider = new ethers.providers.Web3Provider(window.ethereum);
    const signer = provider.getSigner();

    // Transaction (0.001 ETH)
    const tx = {
        to: await signer.getAddress(),
        value: ethers.utils.parseEther("0.001")
    };

    const transaction = await signer.sendTransaction(tx);
    await transaction.wait();

    alert("0.001 ETH deducted successfully!");

} catch (error) {
    console.error(error);
    alert("Transaction failed or rejected");
}

}

index.html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Add Numbers with ETH Deduction</title>
    <script src="https://cdn.jsdelivr.net/npm/ethers@5.7.2/dist/ethers.umd.min.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            padding: 40px;
        }

        input, button {
            padding: 10px;
            margin: 5px;
        }
    </style>
</head>

<body>

<h2>Add Two Numbers (ETH Deduction)</h2>

<input type="number" id="num1" placeholder="Number 1" />
<input type="number" id="num2" placeholder="Number 2" />

<br><br>

<button onclick="addAndPay()">Add</button>

<h3 id="result"></h3>

<script src="app.js"></script>

</body>
</html>

Prac 8 -
Donation.sol

contract Donation {
    address public owner;

    mapping(address => uint) public balances;

    event Donated(address indexed from, uint256 amount);

    constructor(){
        owner = msg.sender;
    }

    function donate() public payable {
        require(msg.value > 0, "Donation amount must be greater than zero");
        balances[msg.sender] += msg.value;
        emit Donated(msg.sender, msg.value);
    }

    function getDonationBalance() public view returns (uint256) {
        return address(this).balance;
    }
}


