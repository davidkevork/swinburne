using System;

namespace SwinAdventure.src
{
    public interface IHaveInventory
    {
        GameObject Locate (string id);

        bool Drop (string id);

        string Name
        {
            get;
        }
    }
}
