Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/jammy64"
  config.vm.network "private_network", ip: "192.168.56.10"
  config.vm.provider "virtualbox" do |vb|
    vb.memory = 4096
    vb.cpus   = 2
    vb.gui    = false
  end

  config.vm.provision "shell", inline: <<-SHELL
    apt-get update -y
    apt-get install -y john

    DEBIAN_FRONTEND=noninteractive apt-get install -y wireshark
    usermod -aG wireshark vagrant

    apt-get install -y openjdk-21-jdk wget unzip
    wget -q https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.2.1_build/ghidra_11.2.1_PUBLIC_20241105.zip -O /tmp/ghidra.zip
    unzip -q /tmp/ghidra.zip -d /opt
    ln -s /opt/ghidra_11.2.1_PUBLIC/ghidraRun /usr/local/bin/ghidra
  SHELL
end
