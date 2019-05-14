using System;
namespace SwinAdventure.src
{
    public class PutCommand : Command
    {
        public PutCommand() : base(new String[] { "put", "drop" }) { }

        public override string Execute(Player p, string[] text)
        {
            int textLength = text.Length;
            if (textLength != 2 && textLength != 4)
            {
                return "I don't know what to put or drop";
            }
            if (text[0] != "drop" || text[0] != "put")
            {
                return "Error in put command";
            }
            string containerId = null;
            if (text.Length == 4)
            {
                containerId = text[3];
            }
            return text[0] == "drop" ? DropItem(p, text[1], text[3]) : PutItem(p, text[1], text[3]);
        }

        private IHaveInventory FetchContainer(Player p, string containerId)
        {
            return containerId == null ? p.Location : p.Locate(containerId) as IHaveInventory;
        }

        private string PutItem(Player p, string thingId, string containerId)
        {
            IHaveInventory container = FetchContainer(p, containerId);
            if (container == null)
            {
                return "I cannot find the " + containerId;
            }
            GameObject containerThing = container.Locate(thingId);
            if (containerThing == null)
            {
                return "I cannot find the " + thingId + (containerId == null ? "" : " in the " + containerId);
            }
            return containerThing.FullDescription;
        }

        private string DropItem(Player p, string thingId, string containerId)
        {
            IHaveInventory container = FetchContainer(p, containerId);
            if (container == null)
            {
                return "I cannot find the " + containerId;
            }
            GameObject containerThing = container.Locate(thingId);
            if (containerThing == null)
            {
                return "I cannot find the " + thingId + (containerId == null ? "" : " in the " + containerId);
            }
            bool dropped = container.Drop(thingId);
            return containerThing.FullDescription;
        }

        public string Description()
        {
            string data = "[put] \tUsage: put <thing> in <container>\n";
            data += "[put] \tUsage: put <thing>\n";
            data += "[drop]  Usage: drop <thing> from <container>\n";
            data += "[drop]  Usage: drop <thing>\n";
            return data;
        }
    }
}
