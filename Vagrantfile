# -*- mode: ruby -*-
# vi: set ft=ruby :
Vagrant.configure("2") do |config|
  config.vm.box = "kalilinux/rolling"
  config.vm.network "private_network", ip: "192.168.56.10"
  config.vm.provider "virtualbox" do |vb|
    vb.name = "snowcrash-utilities"
    vb.memory = "2048"
    vb.cpus = 2
    vb.gui = true
  end
  config.vm.provision "shell", reboot:true,inline: <<-SHELL
    sudo apt-get update
    sudo apt-get install -y kali-desktop-xfce
  SHELL
end
