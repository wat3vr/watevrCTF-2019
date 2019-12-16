sudo apt-get update

sudo apt-get install python3-pip python3-setuptools python3-wheel pandoc libssl1.0-dev gcc-multilib binwalk zip p7zip-full awscli sagemath

# python
python3 -m pip install --upgrade -r requirements.txt --user

# rust
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs/ > rustup_install
chmod +x rustup_install
./rustup_install -q -y
source $HOME/.cargo/env
rustup install nightly
rustup default nightly
rm rustup_install

# node
curl -sL https://deb.nodesource.com/setup_13.x | sudo -E bash -
sudo apt install -y nodejs
npm install
