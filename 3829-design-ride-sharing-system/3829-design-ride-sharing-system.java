class RideSharingSystem {
    Deque<Integer> Rider,Driver;
    public RideSharingSystem() {
         Rider = new ArrayDeque<>();
         Driver = new ArrayDeque<>();
    }
    
    public void addRider(int riderId) {
        Rider.addLast(riderId);
    }
    
    public void addDriver(int driverId) {
        Driver.addLast(driverId);
    }
    
    public int[] matchDriverWithRider() {

        if(Driver.size()>=1 && Rider.size()>=1) 
   { int a = Driver.getFirst(); Driver.removeFirst();
    int b = Rider.getFirst(); Rider.removeFirst();

    return new int[]{a,b};}
        return new int[]{-1,-1};
    }
    
    public void cancelRider(int riderId) {
        if(Rider.contains(riderId)) Rider.remove(riderId);
    }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem obj = new RideSharingSystem();
 * obj.addRider(riderId);
 * obj.addDriver(driverId);
 * int[] param_3 = obj.matchDriverWithRider();
 * obj.cancelRider(riderId);
 */