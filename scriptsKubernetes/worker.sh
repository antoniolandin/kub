# Authors: Antonio Cabrera y Alejandro Gómez
# Group: 3º MAIS  2023/2024
# Description: Instalación de Kubernetes en un nodo worker

sudo apt purge docker*
sudo rm -r /etc/docker/
sudo rm -r /etc/apt/sources.list.d/docker.list 
sudo rm -r /etc/apt/sources.list.d/kubernetes.list
sudo apt purge containerd
sudo rm -r /etc/containerd
sleep 10
sudo apt-get update && sudo apt-get install -y apt-transport-https gnupg2 curl

curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.kubernetes.io kubernetes-xenial main" | sudo tee -a /etc/apt/sources.list.d/kubernetes.list

#apagar la swap
sudo sed -i '/ swap / s/^\(.*\)$/#\1/g' /etc/fstab
sudo swapoff -a

sudo apt-get update
sudo apt-get install -y kubeadm=1.25.0-00 kubelet=1.25.0-00 kubectl=1.25.0-00 kubernetes-cni=1.2.0-00 cri-tools=1.25.0-00


sudo apt-get install -y containerd
sudo apt-get install -y docker.io
sudo apt-get install -y conntrack
 
sudo modprobe overlay
sudo modprobe br_netfilter
 
sudo tee /etc/sysctl.d/kubernetes.conf<<EOF
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
net.ipv4.ip_forward = 1
EOF
 
sudo tee /etc/docker/daemon.json <<EOF
{
  "exec-opts": ["native.cgroupdriver=systemd"],
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "100m"
  },
  "storage-driver": "overlay2"
}
EOF
 
sudo systemctl daemon-reload 
sudo systemctl restart docker
sudo systemctl enable docker.service
sudo systemctl enable kubelet.service
sleep 5

# Conectar con el nodo master
sudo kubeadm join 172.31.58.73:6443 --token rm9vto.9i15qdne8jc7x6l0 \
        --discovery-token-ca-cert-hash sha256:ee071b7cc28de90e40bf920ac6430527b11b758fdcfbdb90ce1f8c07b750e60c