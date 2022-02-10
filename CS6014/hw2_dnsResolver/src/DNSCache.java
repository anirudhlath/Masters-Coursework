import java.util.HashMap;

public class DNSCache {
    static HashMap<DNSQuestion, DNSRecord> map = new HashMap<>();

    // TODO: Check against TTL, if its too old, remove it and return not found!

    static boolean isCached(DNSMessage message) {
        for (int i = 0; i < message.questions.length; i++) {
            if (!map.containsKey(message.questions[i])) {
                if (DNSServer.debug > 0) {
                    System.out.println("\nRecord not found, forwarding to Google!\n");
                }
                return false;
            }
        }
        return true;
    }

    public static DNSRecord fetchRecord(DNSMessage message) {
        if (DNSServer.debug > 0) {
            System.out.println("\nFetching record from cache!\n");
        }
        return map.get(message.questions[0]);
    }

    public static void insertRecord(DNSMessage message, DNSMessage googleMessage) {
        if (DNSServer.debug > 0) {
            System.out.println("\nInserting record into cache!\n");
        }
        map.put(message.questions[0], googleMessage.answers[0]);
    }

}
